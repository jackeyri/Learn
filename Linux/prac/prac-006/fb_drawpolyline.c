 
#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <sys/ioctl.h>  
#include <fcntl.h>          
#include <linux/fb.h>  
#include <sys/mman.h>  

#include <math.h>       /* sin */
#define PI 3.14159265


// TODO-2 
void draw_point(char *buf,  // memory buf
struct fb_var_screeninfo vinfo, 
struct fb_fix_screeninfo finfo,
int x, int y,               // 点坐标(x, y)
int R, int G, int B)        // 颜色
{ 
    // TODO-2  防止越界
    if(???){
        return;
    }

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

void draw_line(char *buf,   // memory buf
struct fb_var_screeninfo vinfo, 
struct fb_fix_screeninfo finfo,
int start_x, int start_y,   // 线的起点坐标(start_x, start_y)
int end_x, int end_y,       // 线的终点坐标(end_x, end_y)
int R, int G, int B)        // 颜色
{
    // 因为要计算斜率，所以先判断在x方向，起点终点是否重合
    if(start_x == end_x){

        int x = start_x;
        int y = 0;

        if (start_y < end_y)
        {
            for(y = start_y; y <= end_y; y++)
            { 
                draw_point(buf, vinfo, finfo, x, y, R, G, B); 
            } 
        }
        else 
        {
            for(y = end_y; y <= start_y; y++)
            {
                draw_point(buf, vinfo, finfo, x, y, R, G, B); 
            }
        }

    }
    else
    {
        // TODO 计算斜率
        double slope = (double) ???;

        int x = 0;
        int y = 0; 

        // 哪个坐标长，就遍历哪个
        if(abs(start_x - end_x) > abs(start_y - end_y))
        {
            if (start_x < end_x)
            {
                for(x = start_x; x <= end_x; x++)
                {
                    //TODO 计算y
                    y = ???;
                    draw_point(buf, vinfo, finfo, x, y, R, G, B);  
                }

            }
            else 
            {
                for(x = end_x; x <= start_x; x++)
                {
                    //TODO 计算y
                    y = ???;
                    draw_point(buf, vinfo, finfo, x, y, R, G, B); 
                }
            }
        }
        else
        {
            if (start_y < end_y)
            {
                for(y = start_y; y <= end_y; y++)
                {
                    //TODO 计算x
                    x = ???;
                    draw_point(buf, vinfo, finfo, x, y, R, G, B); 
                }
            }
            else 
            {
                for(y = end_y; y <= start_y; y++)
                {
                    //TODO 计算x
                    x = ???;
                    draw_point(buf, vinfo, finfo, x, y, R, G, B); 
                }
            } 
        } 
      
    }
}


void draw_polyline(char *buf,  // memory buf
struct fb_var_screeninfo vinfo, 
struct fb_fix_screeninfo finfo,
int *pt_xs,   				// 端点x坐标，数组
int *pt_ys,       			// 端点y坐标，数组
int num,                  	// 端点数量
int R, int G, int B)        // 颜色
{ 
    // TODO 
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

    // TODO-2
    // 实现函数draw_point() 
    // 实现函数draw_line() 
	// 实现函数draw_polyline() 


    // TODO-3
    // 利用函数draw_polyline()
    // 在屏幕上画一个正六边形，边长200
	// 颜色红色
	// 左上角端点(100, 100)
    int start_x = 100;
    int start_y = 100; // 左上角端点(100, 100)
    int length = 200;  // 边长200 
     
    

    // 释放映射的缓存
    if (buf != NULL 
	&& buf != MAP_FAILED){
		munmap (buf, screensize); 
	} 

    // 关闭fbfd
    close(fbfd);  

    return 0;  
}  





 