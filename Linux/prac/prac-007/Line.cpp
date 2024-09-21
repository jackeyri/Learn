#include "Line.h"


VecPt CLine::ToPoints() 
{  
	VecPt ptVec;

	// 因为要计算斜率，所以先判断在x方向，起点终点是否重合
    if(m_start.x == m_end.x){

        int x = m_start.x;
        int y = 0;

        if (m_start.y < m_end.y)
        {
            for(y = m_start.y; y <= m_end.y; y++)
            { 
                ptVec.push_back(CPoint(x, y, m_color)); 
            } 
        }
        else 
        {
            for(y = m_end.y; y <= m_start.y; y++)
            {
                ptVec.push_back(CPoint(x, y, m_color)); 
            }
        }

    }
    else
    {
        // TODO 计算斜率
        double slope =  (double) ???;
         
        int x = 0;
        int y = 0;

        // 哪个坐标长，就遍历哪个
        if(abs(m_start.x - m_end.x) > abs(m_start.y - m_end.y))
        {
           if (m_start.x < m_end.x)
            {
                for(x = m_start.x; x <= m_end.x; x++)
                {
                    //TODO 计算y
                    y = ???;
                    ptVec.push_back(CPoint(x, y, m_color)); 
                }
            }
            else 
            {
                for(x = m_end.x; x <= m_start.x; x++)
                {
                    //TODO 计算y
                    y = ???;
                    ptVec.push_back(CPoint(x, y, m_color)); 
                }
            } 
        }
        else
        {
            if (m_start.y < m_end.y)
            {
                for(y = m_start.y; y <= m_end.y; y++)
                {
                    //TODO 计算x
                    x =  ???;
                    ptVec.push_back(CPoint(x, y, m_color)); 
                }
            }
            else 
            {
                for(y = m_end.y; y <= m_start.y; y++)
                {
                    //TODO 计算x 
                    x = ???;
                    ptVec.push_back(CPoint(x, y, m_color)); 
                }
            } 
        }
        
    }  

	return ptVec; 
}