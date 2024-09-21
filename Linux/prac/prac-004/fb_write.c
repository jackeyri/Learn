#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <sys/ioctl.h>  
#include <fcntl.h>          
#include <linux/fb.h>  
#include <sys/mman.h>  
  
  
// TODO-4
// 将以上画点过程封装成一个函数 
void draw_point(char *buf,  // memory buf
struct fb_var_screeninfo vinfo, 
struct fb_fix_screeninfo finfo,
int x, int y,               // 点坐标(x, y)
int R, int G, int B)        // 颜色
{ 
    // 点对应的颜色值 ARGB，注意大小端
    int color = R<<16 | G<<8 | B; // 左移，按位或
    

    //  TODO-2 确定一个点的位置
    // 1. 一个点在framebuffer上坐标(x, y)，如何确定其在buf上的位置location 
    // 3. 虚拟屏幕与实际屏幕的坐标偏移是 xoffset, yoffset
    // 4. 虚拟屏幕一行的长度是 line_length
    // 5. 则 location = (x + xoffset) * 每个像素所需byte + (y + yoffset) * line_length
    int location = ???;

    // 在buf的相应位置location处设置颜色color
    *((int*)(buf + location)) = color; 

    // ARGB，注意大小端
    // *(buf + location) = B;
    // *(buf + location + 1) = G;
    // *(buf + location + 2) = R; 
}



int main(int argc, char *argv[])  
{   

    int fbfd = -1;   // 设备描述符 

    // 以读写方式O_RDWR打开 /dev/fb0，
    // 返回值赋值给fbfd 
    fbfd = open("/dev/fb0", O_RDWR);
    if (fbfd < 0) {  
            printf("打开 fb0 失败\n");  
         return -1;  
    } 

    int res = -1; 
    struct fb_var_screeninfo vinfo;   
    // ioctl获取设备显示特性信息结果存入vinfo
    res = ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo);
    if (res < 0) {  
        printf("ioctl获得fb_var_screeninfo失败 %d\n",res);  
        return -1;
    }  

    printf("虚拟屏幕相对实际屏幕的偏移 %d %d\n", vinfo.xoffset, vinfo.yoffset);  
 
	struct fb_fix_screeninfo finfo;
    res = ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo);
    if (res < 0) {  
        printf("ioctl获得fb_fix_screeninfo失败 %d\n",res);  
        return -1;
    }   
    printf("虚拟屏幕一行的长度 %d\n", finfo.line_length);  

    
    // TODO-1 虚拟屏幕大小，单位byte 
    // 1. mmap作用，把framebuffer的缓存(二维)映射到内存的buf中(一维数组)
    // 2. 为了进行正确的映射，需要知道framebuffer的缓的大小screensize(单位byte)
    // 3. 虚拟屏幕分辨率 xres_virtual, yres_virtual
    // 4. screensize = xres_virtual * yres_virtual * 每个像素所需byte
    int screensize = ???; 
 

    // 把framebuffer映射到内存，之后就可以直接操作framebuffer了
    char *buf = (char *)mmap(NULL, screensize, 
    PROT_READ|PROT_WRITE, MAP_SHARED, 
    fbfd, 0);

    // 需要绘制的点坐标
    int x = 300;
    int y = 300;  
 
    // 点对应的颜色值 ARGB，注意大小端
    int R = 255;
    int G = 0;
    int B = 0;
    int color = R<<16 | G<<8 | B; // 左移，按位或
    

    //  TODO-2 确定一个点的位置
    // 1. 一个点在framebuffer上坐标(x, y)，如何确定其在buf上的位置location 
    // 3. 虚拟屏幕与实际屏幕的坐标偏移是 xoffset, yoffset
    // 4. 虚拟屏幕一行的长度是 line_length
    // 5. 则 location = (x + xoffset) * 每个像素所需byte + (y + yoffset) * line_length
    int location = ???;

    // 在buf的相应位置location处设置颜色color
    *((int*)(buf + location)) = color; 

    // ARGB，注意大小端
    // *(buf + location) = B;
    // *(buf + location + 1) = G;
    // *(buf + location + 2) = R; 
 


    // TODO-4
    // 将以上画点过程封装成一个函数 
    // draw_point(char *buf, 
    // struct fb_var_screeninfo vinfo,
    // struct fb_fix_screeninfo finfo,
    // int x, int y, int R, int G, int B)


    // TODO-5
    // 利用函数draw_point()
    // 分别在 屏幕四个角(向内偏移100)，和中心处画5个点 
    // 颜色是红色 , 注意, 屏幕的大小是实际屏幕的大小, 屏幕的原点在左上角
 

    // 释放映射的缓存
    if (buf != NULL 
	&& buf != MAP_FAILED){
		munmap (buf, screensize); 
	} 

    // 关闭fbfd
    close(fbfd);  

    return 0;  
}  