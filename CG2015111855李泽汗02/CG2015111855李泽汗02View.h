
// CG2015111855李泽汗02View.h: CCG2015111855李泽汗02View 类的接口
//

#pragma once


class CCG2015111855李泽汗02View : public CView
{
protected: // 仅从序列化创建
	CCG2015111855李泽汗02View();
	DECLARE_DYNCREATE(CCG2015111855李泽汗02View)

// 特性
public:
	CCG2015111855李泽汗02Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CCG2015111855李泽汗02View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // CG2015111855李泽汗02View.cpp 中的调试版本
inline CCG2015111855李泽汗02Doc* CCG2015111855李泽汗02View::GetDocument() const
   { return reinterpret_cast<CCG2015111855李泽汗02Doc*>(m_pDocument); }
#endif

