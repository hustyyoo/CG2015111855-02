#pragma once

#define ROUND(a) ((int)(a+0.5))

class CCGDrawDC:public CClientDC
{
public:
	CCGDrawDC(CWnd* pWnd);

	//DDA画线算法
	//(x1,y1)(x2,y2)为线段两端点坐标,color为绘制颜色
	void LineDDA(int x1, int y1, int x2, int y2, COLORREF color);

	//Bresenham画线算法
	//(x1,y1)(x2,y2)为线段两端点坐标,color为绘制颜色
	void LineBres(int x1, int y1, int x2, int y2, COLORREF color);

	//中点画线算法
	//(x1,y1)(x2,y2)为线段两端点坐标,color为绘制颜色
	void LineMidpoint(int x1, int y1, int x2, int y2, COLORREF color);
	
	~CCGDrawDC();
};

