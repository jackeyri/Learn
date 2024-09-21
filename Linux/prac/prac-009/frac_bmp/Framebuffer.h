#ifndef XXXXX_FRAMEBUFFER
#define XXXXX_FRAMEBUFFER

#include "Point.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <linux/kd.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <string.h>
#include <errno.h>

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

class CFramebuffer
{
public:
	CFramebuffer();
	~CFramebuffer();
	int Init();
	void DrawPoint(CPoint pt);
	void DrawPoints(VecPt ptVec);
	
	int GetWidth();
	int GetHeight();
	CPoint GetCenter();
	
	int SaveBmp(char* filename);


protected:
	void UnInit();

protected:
	char *buf;
	int fbfd;
	struct fb_var_screeninfo vinfo;
	struct fb_fix_screeninfo finfo;
	long int screensize;
};

#endif // XXXXX_FRAMEBUFFER
