// TuoyuanEdit.cpp: 实现文件
//

#include "pch.h"
#include "CGHomework1.h"
#include "afxdialogex.h"
#include "TuoyuanEdit.h"


// TuoyuanEdit 对话框

IMPLEMENT_DYNAMIC(TuoyuanEdit, CDialog)

TuoyuanEdit::TuoyuanEdit(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_TuoyuanEdit, pParent)
	, a(0)
	, b(0)
{
	this->pParent = pParent;
}

TuoyuanEdit::~TuoyuanEdit()
{
}

void TuoyuanEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, a);
	DDX_Text(pDX, IDC_EDIT2, b);
}


BEGIN_MESSAGE_MAP(TuoyuanEdit, CDialog)
	ON_BN_CLICKED(IDOK, &TuoyuanEdit::OnBnClickedOk)
END_MESSAGE_MAP()


// TuoyuanEdit 消息处理程序


void TuoyuanEdit::OnBnClickedOk()
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
	int x = 0, y = b;
	pDC->SetPixel(500 + x, 500 + y, RGB(255, 0, 0));
	pDC->SetPixel(500 - x, 500 + y, RGB(255, 0, 0));
	pDC->SetPixel(500 + x, 500 - y, RGB(255, 0, 0));
	pDC->SetPixel(500 - x, 500 - y, RGB(255, 0, 0));
	double d1 = b * b + a * a * (-b + 0.25);
	while (b * b * x < a * a * y)
	{
		if (d1 < 0)
		{
			d1 += b * b * (2 * x + 3);
			x++;
		}
		else
		{
			d1 += (b * b * (2 * x + 3) + a * a * (-2 * y + 2));
			x++; y--;
		}

		pDC->SetPixel(500 + x, 500 + y, RGB(255, 0, 0));
		pDC->SetPixel(500 - x, 500 + y, RGB(255, 0, 0));
		pDC->SetPixel(500 + x, 500 - y, RGB(255, 0, 0));
		pDC->SetPixel(500 - x, 500 - y, RGB(255, 0, 0));
	}
	double d2 = sqrt((double)b * (x + 0.5)) + sqrt((double)a * (y - 1)) - sqrt((double)a * b);
	while (y > 0)
	{
		if (d2 < 0)
		{
			d2 += b * b * (2 * x + 2) + a * a * (-2 * y + 3);
			x++;
			y--;
		}
		else
		{
			d2 += a * a * (-2 * y + 3);
			y--;
		}
		pDC->SetPixel(500 + x, 500 + y, RGB(255, 0, 0));
		pDC->SetPixel(500 - x, 500 + y, RGB(255, 0, 0));
		pDC->SetPixel(500 + x, 500 - y, RGB(255, 0, 0));
		pDC->SetPixel(500 - x, 500 - y, RGB(255, 0, 0));
	}
}
