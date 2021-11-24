#pragma once
#include "afxdialogex.h"


// YuanEdit 对话框

class YuanEdit : public CDialog
{
	DECLARE_DYNAMIC(YuanEdit)

public:
	YuanEdit(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~YuanEdit();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_YuanEdit };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CWnd* pParent;
	int banjing;
	afx_msg void OnBnClickedOk();
};
