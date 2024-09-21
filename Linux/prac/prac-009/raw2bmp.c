#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/soundcard.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>       
#include <linux/fb.h>  
#include <sys/mman.h>  
  

//bmp 位图文件头
typedef struct tagBITMAPFILEHEADER 
{ 
unsigned short bfType;      //位图文件的类型，必须为 0x4d42
unsigned int bfSize;        //位图文件的大小，以字节为单位 
unsigned short bfReserved1; //位图文件保留字，必须为0 
unsigned short bfReserved2; //位图文件保留字，必须为0 
unsigned int bfOffBits;     //位图数据的起始位置，从文件头开始到位图数据之间的偏移量，以字节为单位  
}__attribute__((packed)) BITMAPFILEHEADER; 

//bmp 位图信息段
typedef struct tagBITMAPINFOHEADER{ 
unsigned int biSize;      //本结构所占用字节数 
int biWidth;              //位图的宽度，以像素为单位 
int biHeight;             //位图的高度，以像素为单位 
//注：biHeight这个值除了用于描述图像的高度之外，它还有另一个用处，就是指明该图像是倒向的位图，还是正向的位图。如果该值是一个正数，说明图像是倒向的，即：数据的第一行其实是图像的最后一行，如果该值是一个负数，则说明图像是正向的。大多数的BMP文件都是倒向的位图，也就是时，高度值是一个正数。
unsigned short biPlanes;  //表示bmp图片的平面数，显然显示器只有一个平面，所以恒等于1
unsigned short biBitCount;//每个像素所占bit数(色深)，其值为1、4、8、16、24、或32之一
unsigned int biCompression; //位图压缩类型，其值是 0(BI_RGB不压缩),1(BI_RLE8压缩类型)或2(BI_RLE4压缩类型)之一 
unsigned int biSizeImage; //位图的大小，以字节为单位 
int biXPelsPerMeter;      //位图水平分辨率，每米像素数 
int biYPelsPerMeter;      //位图垂直分辨率，每米像素数 
unsigned int biClrUsed;   //位图实际使用的颜色表中的颜色数，如果是0，则说明使用所有调色板项
unsigned int biClrImportant;//位图显示过程中重要的颜色数，如果是0，表示都重要
}__attribute__((packed)) BITMAPINFOHEADER;




int main(int argc, char *argv[])
{

    // TODO-1 判断输入参数个数 
    if(argc != 2){
        printf("参数个数不是2个 \n");
        return -1;
    }

    // TODO-2 第二个参数作为保存文件名
    char *filename = argv[1];

    int fbfd = -1;   // 设备描述符  
    // TODO-3 以只读方式打开 /dev/fb0，
    // 返回值赋值给fbfd 
    fbfd = open("/dev/fb0", O_RDONLY);
    if (fbfd < 0) {  
            printf("打开 fb0 失败\n");  
         return -1;  
    } 

    int res = -1; 
    struct fb_var_screeninfo vinfo;   
    // ioctl获取设备显示特性信息结果存入vinfo
    res = ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo);
    if ( res < 0 ) {  
        printf("ioctl获得fb_var_screeninfo失败 %d\n",res);  
        return -1;
    }   

    int bmpfd = -1;   // bmp件描述符 
    // TODO-4 以 O_WRONLY | O_CREAT 方式打开 文件filename
    // 返回值赋值给bmpfd 
    bmpfd = open(filename, O_WRONLY | O_CREAT);
    if (bmpfd < 0) {  
        printf("打开 %s 失败\n", filename);  
        return -1;  
    } 
    
    char *buf = NULL;
    // TODO-5 动态分配buf，大小是虚拟屏幕，一屏数据所需的字节数
    // 提示使用malloc 
    int vfbsize = vinfo.xres_virtual * vinfo.yres_virtual * (vinfo.bits_per_pixel / 8);  
    buf = malloc(vfbsize); 
    if(buf == NULL){
        printf("动态分配buf失败\n");  
        return -1;  
    }

    // TODO-6 一次从fbfd中读取数据到buf 
    res = read(fbfd, buf, vfbsize);
    if(res < 0 ){
        printf("读取framebuffer失败\n");  
        return -1;  
    }
    

    // bmp 位图文件头
    BITMAPFILEHEADER bfh;  

    // TODO-7 设置 bfType
    bfh.bfType = 0x4d42;  // 位图文件的类型，必须为 0x4d42

    // TODO-8 设置 bfSize
    bfh.bfSize = vfbsize
            + sizeof(BITMAPFILEHEADER)  
            + sizeof(BITMAPINFOHEADER)  
            ;  // 位图文件的大小，以字节为单位  

    // TODO-9 设置 bfOffBits
    bfh.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);// 位图数据的起始位置，从文件头开始到位图数据之间的偏移量，以字节为单 

    bfh.bfReserved1 = 0; // 位图文件保留字，必须为0 
    bfh.bfReserved2 = 0; // 位图文件保留字，必须为0 

    // bmp 位图信息段
    BITMAPINFOHEADER bih;  

    // TODO-10 设置 bfOffBits   
    bih.biSize = sizeof(BITMAPINFOHEADER); // 本结构所占用字节数   

    // TODO-11 设置 bfOffBits
    bih.biWidth = vinfo.xres_virtual;  // 位图的宽度，以像素为单位 

    // TODO-12 设置 bfOffBits
    bih.biHeight = - vinfo.yres_virtual;// 位图的高度，以像素为单位 

    // TODO-13 设置 bfOffBits
    bih.biBitCount = vinfo.bits_per_pixel;// 每个像素所占bit数(色深)

    // TODO-14 设置 bfOffBits
    bih.biSizeImage = vfbsize; //位图的大小，以字节为单位 

    bih.biCompression = 0;// 位图压缩类型，其值是 0(BI_RGB不压缩)
    bih.biPlanes = 1;// 表示bmp图片的平面数，显然显示器只有一个平面，所以恒等于1
    bih.biXPelsPerMeter = 100 ;// 位图水平分辨率，每米像素数 
    bih.biYPelsPerMeter = 100 ;// 位图垂直分辨率，每米像素数   
    bih.biClrUsed = 0;// 位图实际使用的颜色表中的颜色数，如果是0，则说明使用所有调色板项
    bih.biClrImportant = 0;// 位图显示过程中重要的颜色数，如果是0，表示都重要
    
    // TODO-15 写入bmp 位图文件头 到 bmpfd 
    res = write(bmpfd, &bfh, sizeof(BITMAPFILEHEADER));  
    if(res  < 0 ){
        printf("写入bmp 位图文件头失败\n");  
        return -1;  
    }

    // TODO-16 写入bmp 位图信息段 到 bmpfd 
    res = write(bmpfd, &bih, sizeof(BITMAPINFOHEADER));  
    if(res  < 0 ){
        printf("写入bmp 位图信息段失败\n");  
        return -1;  
    }

    // TODO-17 写入raw 数据 到 bmpfd 
    res = write(bmpfd, buf, vfbsize);
    if(res  < 0 ){
        printf("写入raw 数据失败\n");  
        return -1;  
    }

    // TODO-18 释放buf
    free(buf);

    // TODO-19 关闭rawfd
    close(bmpfd);  
    
    // TODO-20 关闭fbfd
    close(fbfd);  
     
    return 0;
 
}
