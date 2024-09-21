#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <sys/ioctl.h>  
#include <fcntl.h>          
#include <linux/fb.h>  
#include <sys/mman.h>  


int main(void)  
{  
    int fbfd = -1;   // 设备描述符 

    // TODO-1 以只读方式打开 /dev/fb0，
    // 返回值赋值给fbfd 
    fbfd = ???;
    if (fbfd < 0) {  
        printf("打开 /dev/fb0 失败\n");  
        return -1;  
    }  

    int res = -1; 
    struct fb_var_screeninfo vinfo;   
    // ioctl获取设备显示特性信息结果存入结构体变量vinfo
    res = ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo);
    if (res < 0) {  
        printf("ioctl获得fb_var_screeninfo失败 %d\n",res);  
        return -1;
    }   

    // TODO-2 打印相关信息
    // 从上面获得的vinfo中，格式化正确的信息
    // 注意，这里的信息不是写死的，而是从结构体变量中得到的 
    printf("实际屏幕分辨率, X: %d, Y: %d, 色深BBP: %d\n", 
    ???, ???, ???);   
 
    // TODO-3 打印相关信息
    printf("虚拟屏幕分辨率, X: %d, Y: %d\n",
    ???, ???);  

    // TODO-4 计算实际屏幕占多少个字节  
    int fbsize = ???; 
    printf("实际屏幕占字节数: %d\n", fbsize);   

    // TODO-5 计算虚拟屏幕占多少个字节  
    // 注意：这里的字节数，应该和 screen.raw大小一致
    int vfbsize = ???; 
    printf("虚拟屏幕占字节数: %d\n", vfbsize);  
    
    // TODO-6 关闭fbfd
    

    return 0;  
}  