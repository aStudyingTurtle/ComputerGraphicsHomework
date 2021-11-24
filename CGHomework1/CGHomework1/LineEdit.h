#pragma once
#include "afxdialogex.h"


// LineEdit 对话框

class LineEdit : public CDialog
{
	DECLARE_DYNAMIC(LineEdit)

public:
	LineEdit(CWnd* pParent = nullptr, int methodtype = 0);   // 标准构造函数
	void static MidPointline(CDC* pDC, int x1, int y1, int x2, int y2);
	virtual ~LineEdit();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LineEdit };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int x1;
	int y1;
	int x2;
	int y2;
	int methodtype;
	CWnd* pParent;
	afx_msg void OnBnClickedOk();
};
