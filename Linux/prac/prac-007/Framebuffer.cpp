#include "Framebuffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>


CFramebuffer::CFramebuffer()
{
    buf = NULL;
    fbfd = -1;
    screensize = 0;
}

CFramebuffer::~CFramebuffer()
{
    UnInit();
}

int CFramebuffer::Init()
{

    // 以读写方式打开 /dev/fb0，
    // 返回值赋值给fbfd
    // 判断打开是否成功，失败直接返回
    fbfd = open("/dev/fb0", O_RDWR);
    if (fbfd < 0)
    {
        printf("打开 fb0 失败\n");
        return -1;
    }

    int res = -1;
    // ioctl获取设备显示特性信息结果存入vinfo
    res = ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo);
    if (res < 0)
    {
        printf("ioctl获得fb_var_screeninfo失败 %d\n", res);
        return -1;
    }

    res = ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo);
    if (res < 0)
    {
        printf("ioctl获得fb_fix_screeninfo失败 %d\n", res);
        return -1;
    }
 

    // TODO 虚拟屏幕大小，单位byte
    // 1. mmap作用，把framebuffer的缓存(二维)映射到内存的buf中(一维数组)
    // 2. 为了进行正确的映射，需要知道framebuffer的缓的大小screensize(单位byte)
    // 3. 虚拟屏幕分辨率 xres_virtual, yres_virtual
    // 4. screensize = xres_virtual * yres_virtual * 每个像素所需byte
    screensize = ???;

    // 把framebuffer映射到内存，之后就可以直接操作framebuffer了
    buf = (char *)mmap(NULL, screensize,
                       PROT_READ | PROT_WRITE, MAP_SHARED,
                       fbfd, 0);
    return 0;
}

void CFramebuffer::UnInit()
{
    // 释放映射的缓存
    if (buf != NULL && buf != MAP_FAILED)
    {
        munmap(buf, screensize);
    }

    // 关闭fbfd
    if (fbfd != -1)
    {
        close(fbfd);
    }
}

int CFramebuffer::GetWidth()
{
    return vinfo.xres;
}

int CFramebuffer::GetHeight()
{
    return vinfo.yres;
}

CPoint CFramebuffer::GetCenter()
{
    return CPoint(vinfo.xres / 2, vinfo.yres / 2);
}

void CFramebuffer::DrawPoint(CPoint pt) //(x.y) 是坐标
{
    // TODO 防止越界
    if (???)
    {
        return;
    }
  
    //  TODO 确定一个点的位置
    // 1. 一个点在framebuffer上坐标(x, y)，如何确定其在buf上的位置location
    // 3. 虚拟屏幕与实际屏幕的坐标偏移是 xoffset, yoffset
    // 4. 虚拟屏幕一行的长度是 line_length
    // 5. 则 location = (x + xoffset) * 每个像素所需byte + (y + yoffset) * line_length
    int location = ???;

    // 在buf的相应位置location处设置颜色color
    *((int *)(buf + location)) = pt.color.v;
}

void CFramebuffer::DrawPoints(VecPt ptVec)
{
    // TODO 遍历所有的Point 并绘制 
    ???; 
}

 