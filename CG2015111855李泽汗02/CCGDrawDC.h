#pragma once

#define ROUND(a) ((int)(a+0.5))

class CCGDrawDC:public CClientDC
{
public:
	CCGDrawDC(CWnd* pWnd);

	//DDA�����㷨
	//(x1,y1)(x2,y2)Ϊ�߶����˵�����,colorΪ������ɫ
	void LineDDA(int x1, int y1, int x2, int y2, COLORREF color);

	//Bresenham�����㷨
	//(x1,y1)(x2,y2)Ϊ�߶����˵�����,colorΪ������ɫ
	void LineBres(int x1, int y1, int x2, int y2, COLORREF color);

	//�е㻭���㷨
	//(x1,y1)(x2,y2)Ϊ�߶����˵�����,colorΪ������ɫ
	void LineMidpoint(int x1, int y1, int x2, int y2, COLORREF color);
	
	~CCGDrawDC();
};

