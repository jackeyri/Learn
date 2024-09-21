#include "Framebuffer.h"
#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <sys/ioctl.h>  
#include <fcntl.h>          
#include <linux/fb.h>  
#include <sys/mman.h>  

#include <math.h>       
#include "Polyline.h"
#include "Line.h"

int main (int argc, char *argv[]) 
{
	CFramebuffer framebuffer;
	framebuffer.Init();

	// TODO
	// 绘制正六边形
	VecPt ptVec; 
	int start_x = 100;
    int start_y = 100; // 左上角端点(100, 100)
    int length = 200;  // 边长200
    
	// 计算每个顶点，并把每个点push_back到vector
    ptVec.push_back(CPoint(start_x, start_y)); // 第一个点
	
	// 其它5个点 
	???;

	// 闭合多段线 
	CPolyline polyline(ptVec, CColor(255, 125, 0), true); 

	// 绘制 
	framebuffer.DrawPoints(polyline.GetPoints());
 
	return 0; 
	
}
