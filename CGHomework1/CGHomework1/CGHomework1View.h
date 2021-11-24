
// CGHomework1View.h: CCGHomework1View 类的接口
//

#pragma once


class CCGHomework1View : public CView
{
protected: // 仅从序列化创建
	CCGHomework1View() noexcept;
	DECLARE_DYNCREATE(CCGHomework1View)

	// 特性
public:
	CCGHomework1Doc* GetDocument() const;

	// 操作
public:

	// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	void static Fill4(CDC* pDC, int x, int y);
	void static Fill8(CDC* pDC, int x, int y);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

	// 实现
public:
	virtual ~CCGHomework1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32775();
	afx_msg void On32776();
	afx_msg void On32777();
	afx_msg void On32778();
	afx_msg void On32780();
	afx_msg void On32781();
	afx_msg void On32783();
	afx_msg void On32784();
	afx_msg void On32785();
	afx_msg void On32787();
	afx_msg void On32788();
	afx_msg void On32789();
	afx_msg void On32790();
	afx_msg void On32791();
	afx_msg void On32793();
	afx_msg void On32794();
	afx_msg void On32795();
	afx_msg void On32798();
	afx_msg void On32799();
	afx_msg void On32800();
	afx_msg void On32801();
	afx_msg void On32802();
	afx_msg void On32797();
};

#ifndef _DEBUG  // CGHomework1View.cpp 中的调试版本
inline CCGHomework1Doc* CCGHomework1View::GetDocument() const
{
	return reinterpret_cast<CCGHomework1Doc*>(m_pDocument);
}
#endif

