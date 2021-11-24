#pragma once
#include "afxdialogex.h"


// TuoyuanEdit 对话框

class TuoyuanEdit : public CDialog
{
	DECLARE_DYNAMIC(TuoyuanEdit)

public:
	TuoyuanEdit(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~TuoyuanEdit();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TuoyuanEdit };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CWnd* pParent;
	int a;
	int b;
	afx_msg void OnBnClickedOk();
};
