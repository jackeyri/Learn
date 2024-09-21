#include "FractalDragon.h"
#include <math.h>
#include <iostream>
 
#include "Polyline.h"

//计算两点之间的长度
double CFractalDragon::GetLength(CPoint &pt1, 
								CPoint & pt2)
{
	return sqrt( (pt1.x - pt2.x) * (pt1.x - pt2.x) 
	           + (pt1.y - pt2.y) * (pt1.y - pt2.y)) ;
}

//计算两点之间的中点
CPoint CFractalDragon::GetCenter(CPoint &pt1, 
								CPoint &pt2)
{
	return CPoint( (pt1.x + pt2.x) / 2, 
	               (pt1.y + pt2.y) / 2);
}

//判断点C 在向量AB的左侧还是右侧
bool CFractalDragon::IsLeft(CPoint &ptA, 
							CPoint &ptB,
							CPoint &ptC)
{
	bool isLeft = false;
	
	//三角形的有向面积
	//ABC逆时针，面积为正，也即C在AB的左侧
	//ABC顺时针，面积为负，也即C在AB的右侧
	//面积为0，则C在AB上
	double signedArea = ptA.x * ptB.y
	                  + ptC.x * ptA.y
					  + ptB.x * ptC.y
					  - ptC.x * ptB.y
					  - ptB.x * ptA.y
					  - ptA.x * ptC.y;
	
	if(signedArea > 0)
	{
		isLeft = true;
	}
	
	return isLeft;
}

//计算两点的垂直中点，得到两个结果，一左，一右
//needLeft 为 true，则返回 左侧的点
CPoint CFractalDragon::GetVerticalCenter(
							 CPoint &start, 
							 CPoint &end,
							 bool needLeft)
{
	CPoint center = GetCenter(start, end);

	double len = GetLength(start, end) / 2; 

	CPoint pt1;
	CPoint pt2; // 一左，一右两个点

	// 因为下面要计算斜率，所以需要判断y坐标是否相等
	if (end.y == start.y)
	{
		pt1.x = center.x;
		pt2.x = pt1.x; 
		pt1.y = len + center.y; 
		pt2.y = -len + center.y;  
	}
	else
	{
		// 斜率
		double slope = (double) -(end.x - start.x) / (end.y - start.y);

		pt1.x = sqrt(len * len / (slope * slope + 1)) + center.x;
		pt2.x = - sqrt(len * len / (slope * slope + 1)) + center.x; 
		pt1.y = slope * (pt1.x - center.x) + center.y;
		pt2.y = slope * (pt2.x - center.x) + center.y; 
	}
 
    // 需要左侧的点
	if(needLeft)
	{
		if(IsLeft(start, end, pt1)) // 判断点1在左侧
		{
			return pt1;
		}
		else
		{
			return pt2;
		}
	}
	else // 需要右侧的点
	{
		if(!IsLeft(start, end, pt1)) // 判断点1在右侧
		{
			return pt1;
		}
		else
		{
			return pt2;
		}
	} 
}


VecPt CFractalDragon::ToPoints() 
{   
	//计算分形龙的顶点
	VecPt vertexs;
	// 如果是0阶，那最终结果就是 起点和终点
	vertexs.push_back(m_start);
	vertexs.push_back(m_end); 

	int step = m_step;
    // 阶数迭代
	while (step-- > 0)
	{ 
		// 这一阶分形龙顶点数量，是上一阶顶点数量*2 -1 
		int pointNum = vertexs.size() * 2 - 1;
		// 这一阶的结果
		VecPt tmpvertexs(pointNum);
		
		// 遍历上一阶的顶点
		for (int i = 0; i < vertexs.size() - 1; i++)
		{
			// 两端的点，直接拿来 
			tmpvertexs[i * 2] = vertexs[i];
			// 中间的新点，偶数取左，奇数取右
			bool needLeft = (i%2 == 0) ? true : false;
			// 计算中间的新点
			tmpvertexs[i * 2 + 1] = GetVerticalCenter(vertexs[i], 
										vertexs[i + 1],
										needLeft);    
		}
		// 最后一个点
		tmpvertexs[tmpvertexs.size() - 1] = vertexs[vertexs.size() - 1]; 
		
		// 最终结果 替换 这一阶的结果
		// 并且，最终结果，作为下一阶迭代时 的 上一阶的结果
		vertexs = tmpvertexs; 
	}

	// 转换成多段线 
	CPolyline polyline(vertexs, m_color, false);
 
	// 返回Points 用于绘图 
	return polyline.GetPoints();
}
