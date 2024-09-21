#include "Polyline.h"
#include "Line.h"

VecPt CPolyline::ToPoints()
{
    VecPt ptVec;

    for (int i = 0; i < m_vertexs.size() - 1; ++i)
    {
        // TODO 每次取出两个点，组成Line 
        // 根据Line 获得绘图用的Points
        // Points 放到 VecPt 的最后 
        ???;  
    }

    // 闭合多段线 
    if (m_closure)
    {
        // 由最后一个点和第一个点闭合，组成Line 
        CLine line(m_vertexs[m_vertexs.size() - 1], m_vertexs[0], m_color);
        // 根据Line 获得绘图用的Points
        VecPt cptVec = line.GetPoints(); 
        // Points 放到 VecPt 的最后 
        ptVec.insert(ptVec.end(),
                     cptVec.begin(), cptVec.end()); 
    }
 

    return ptVec;
}