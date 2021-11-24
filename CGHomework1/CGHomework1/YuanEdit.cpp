// YuanEdit.cpp: 实现文件
//

#include "pch.h"
#include "CGHomework1.h"
#include "afxdialogex.h"
#include "YuanEdit.h"


// YuanEdit 对话框

IMPLEMENT_DYNAMIC(YuanEdit, CDialog)

YuanEdit::YuanEdit(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_YuanEdit, pParent)
	, banjing(0)
{
	this->pParent = pParent;
}

YuanEdit::~YuanEdit()
{
}

void YuanEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, banjing);
}


BEGIN_MESSAGE_MAP(YuanEdit, CDialog)
	ON_BN_CLICKED(IDOK, &YuanEdit::OnBnClickedOk)
END_MESSAGE_MAP()


// YuanEdit 消息处理程序


void YuanEdit::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnOK();
	CDC* pDC = pParent->GetDC();
	CRect rect;
	GetClientRect(&rect);

	// 画坐标轴
	pDC->MoveTo(0, rect.Height() / 2);
	pDC->LineTo(rect.Width(), rect.Height() / 2);
	pDC->MoveTo(rect.Width() / 2, 0);
	pDC->LineTo(rect.Width() / 2, rect.Height());

	//移动坐标原点到客户区中心
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetViewportOrg(0, 0);
	pDC->SetViewportExt(rect.right, rect.bottom);
	pDC->SetWindowOrg(0, 0);
	pDC->SetWindowExt(1000, 1000);
	//画图
	double x, y, d;
	x = 0;
	y = (int)banjing;
	d = 3 - 2 * banjing;
	while (x < y) {
		pDC->SetPixel(500 + x, 500 + y, RGB(255, 0, 0));
		pDC->SetPixel(500 + y, 500 + x, RGB(255, 0, 0));
		pDC->SetPixel(500 + y, 500 - x, RGB(255, 0, 0));
		pDC->SetPixel(500 + x, 500 - y, RGB(255, 0, 0));
		pDC->SetPixel(500 - x, 500 - y, RGB(255, 0, 0));
		pDC->SetPixel(500 - y, 500 - x, RGB(255, 0, 0));
		pDC->SetPixel(500 - y, 500 + x, RGB(255, 0, 0));
		pDC->SetPixel(500 - x, 500 + y, RGB(255, 0, 0));
		if (d < 0) {
			d = d + 4 * x + 6;
		}
		else {
			d = d + 4 * (x - y) + 10;
			y--;
		}
		x++;
	}
	if (x == y) {
		pDC->SetPixel(500 + x, 500 + y, RGB(255, 0, 0));
		pDC->SetPixel(500 + y, 500 + x, RGB(255, 0, 0));
		pDC->SetPixel(500 + y, 500 - x, RGB(255, 0, 0));
		pDC->SetPixel(500 + x, 500 - y, RGB(255, 0, 0));
		pDC->SetPixel(500 - x, 500 - y, RGB(255, 0, 0));
		pDC->SetPixel(500 - y, 500 - x, RGB(255, 0, 0));
		pDC->SetPixel(500 - y, 500 + x, RGB(255, 0, 0));
		pDC->SetPixel(500 - x, 500 + y, RGB(255, 0, 0));
	}
}
