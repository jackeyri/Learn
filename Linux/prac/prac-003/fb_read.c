#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <sys/ioctl.h>  
#include <fcntl.h>          
#include <linux/fb.h>  
#include <sys/mman.h>  
  
  
  


int main(int argc, char *argv[])  
{  

    // TODO-1 判断输入参数个数 
    if(???){
        printf("参数个数不是2个 \n");
        return -1;
    } 

    // TODO-2 第二个参数作为保存文件名
    char *filename = ???;

    int fbfd = -1;   // 设备描述符 

    // TODO-3 以只读方式打开 /dev/fb0，
    // 返回值赋值给fbfd 
    fbfd = ???;
    if (fbfd < 0) {  
         printf("打开 fb0 失败\n");  
         return -1;  
    } 

    int res = -1; 
    struct fb_var_screeninfo vinfo;   
    // ioctl获取设备显示特性信息结果存入vinfo
    res = ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo)
    if ( res < 0 ) {  
        printf("ioctl获得fb_var_screeninfo失败 %d\n",res);  
        return -1;
    }  


    int rawfd = -1;   // raw文件描述符 
    // TODO-4 以 O_WRONLY | O_CREAT 方式打开 文件filename
    // 返回值赋值给rawfd 
    rawfd = ???;
    if ( rawfd < 0 ) {  
        printf("打开 %s 失败\n", filename);  
        return -1;  
    } 

    
    char *buf = NULL; 
    // TODO-5 动态分配buf，大小是虚拟屏幕，一屏数据所需的字节数
    // 提示使用malloc  
    buf = ???;  
    if(buf == NULL){
        printf("动态分配buf失败\n");  
        return -1;  
    }  

    // TODO-6 一次从fbfd中读取数据到buf 
    res = ???;
    if(res < 0){
        printf("读取framebuffer失败\n");  
        return -1;  
    }
    
    // TODO-7 把buf数据写入rawfd中  
    res = ???;
    if(res  < 0){
        printf("写入raw失败\n");  
        return -1;  
    }

    // TODO-8 释放buf 

    // TODO-9 关闭rawfd 
    
    // TODO-10 关闭fbfd 

    return 0;  
}  