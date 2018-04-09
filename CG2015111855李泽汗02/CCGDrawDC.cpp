#include "stdafx.h"
#include "CCGDrawDC.h"


CCGDrawDC::CCGDrawDC(CWnd* pWnd):CClientDC(pWnd){  }


void CCGDrawDC::LineDDA(int x1, int y1, int x2, int y2, COLORREF color)
{
	int dx = x2 - x1, dy = y2 - y1, steps, k;
	float xIncrement, yIncrement, x = x1, y = y1;
	if (abs(dx) > abs(dy)) steps = abs(dx);
	else steps = abs(dy);
	xIncrement = dx / (float)steps;
	yIncrement = dy / (float)steps;
	SetPixel(ROUND(x), ROUND(y), color);
	for (k = 0; k<steps; k++)
	{
		x += xIncrement;
		y += yIncrement;
		SetPixel(ROUND(x), ROUND(y), color);
	}
}

void CCGDrawDC::LineBres(int x1, int y1, int x2, int y2, COLORREF color)
{
	int x = x1, y = y1;
	int dx = abs(x2 - x1), dy = abs(y2 - y1);	//x,y偏移量
	int ux = (x2 - x1) > 0 ? 1 : -1;
	int uy = (y2 - y1) > 0 ? 1 : -1;			//最大位移量的方向，+1或者-1		
	int two_dx = dx << 1, two_dy = dy << 1;	//位运算计算两倍的偏移量的绝对值

	if (dx > dy) {									//x为最大位移
		int e = two_dy - two_dx;					//初始值为2|dy| - 2|dx|						
		while (x != x2) {
			SetPixel(x, y, color);					//画点
			if (e > 0) 								//e > 0 ，y方向增加/减少
				y += uy, e = e + two_dy - two_dx;	// e = e + 2|dy| - 2|dx|
			else
				e = e + two_dy;						//e < 0 ,e = e + 2|dy|
			x += ux;
		}
		SetPixel(x2, y2, color);					//补充终点
	}
	else {											//y为最大位移	
		int e = two_dx - two_dy;
		while (y != y2) {
			SetPixel(x, y, color);
			if (e > 0)
				x += ux, e = e + two_dx - two_dy;
			else
				e = e + two_dx;
			y += uy;
		}
		SetPixel(x2, y2, color);
	}
}

void CCGDrawDC::LineMidpoint(int x1, int y1, int x2, int y2, COLORREF color)
{
	int x = x1, y = y1;
	int a = y1 - y2, b = x2 - x1;			//a和b
	int ux = (b >= 0 ? 1 : (b = -b, -1));
	int uy = (a <= 0 ? 1 : (a = -a, -1));	//x和y增量的方向+1或者-1，以及调整a和b的正负
	int d, d1, d2;

	if (-a > b) {						//斜率绝对值大于1
		d = 2 * b + a;					//d的初值为2b +a
		d1 = 2 * b;
		d2 = 2 * (a + b);				//d1和d2
		while (y != y2)
		{
			SetPixel(x, y, color);		//画点
			if (d < 0)					//d < 0
				d += d1;				//x不动，d = d + d1
			else
				x += ux, d += d2;		//d>=0,x移动一个偏移量，d = d + d2
			y += uy;					//y移动一个偏移量
		}
		SetPixel(x2, y2, color);			//补充终点	
	}

	else {								//斜率绝对值小于等于1
		d = 2 * a + b;
		d1 = 2 * a;
		d2 = 2 * (a + b);
		while (x != x2)
		{
			SetPixel(x, y, color);
			if (d < 0)
				y += uy, d += d2;
			else
				d += d1;
			x += ux;
		}
		SetPixel(x2, y2, color);
	}
}

CCGDrawDC::~CCGDrawDC(){  }
