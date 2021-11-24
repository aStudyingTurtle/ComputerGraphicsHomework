// LineEdit.cpp: 实现文件
//

#include "pch.h"
#include "CGHomework1.h"
#include "afxdialogex.h"
#include "LineEdit.h"


// LineEdit 对话框

IMPLEMENT_DYNAMIC(LineEdit, CDialog)

LineEdit::LineEdit(CWnd* pParent /*=nullptr*/, int methodtype /*0*/)
	: CDialog(IDD_LineEdit, pParent)
	  , x1(0)
	  , y1(0)
	  , x2(0)
	  , y2(0)

{
	//methodtype =0:DDA
	this->methodtype = methodtype;
	this->pParent = pParent;
}

LineEdit::~LineEdit()
{
}

void LineEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x1);
	DDX_Text(pDX, IDC_EDIT2, y1);
	DDX_Text(pDX, IDC_EDIT3, x2);
	DDX_Text(pDX, IDC_EDIT4, y2);
}


BEGIN_MESSAGE_MAP(LineEdit, CDialog)
	ON_BN_CLICKED(IDOK, &LineEdit::OnBnClickedOk)
END_MESSAGE_MAP()


// LineEdit 消息处理程序

void LineEdit::MidPointline(CDC* pDC, int x1, int y1, int x2, int y2)
{
	return;
}

void LineEdit::OnBnClickedOk()
{
	CDialog::OnOK();
	// TODO: 在此添加控件通知处理程序代码
	if (this->methodtype == 0)
	{
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
		int steps;
		int dx, dy;
		float x, y;
		float delta_x, delta_y;
		int point_x, point_y;
		dx = x2 - x1;
		dy = y2 - y1;
		if (abs(dx) > abs(dy))
			steps = dx;
		else
			steps = dy;
		x = x1;
		y = y1;
		delta_x = float(dx * 1.0) / abs(steps);
		delta_y = float(dy * 1.0) / abs(steps); //计算相邻两个点的增量
		pDC->SetPixel(x, y, RGB(255, 0, 0));
		for (int i = 0; i < abs(steps); i++)
		{
			x = x + delta_x;
			y = y + delta_y;
			point_x = int(x + 0.5);
			point_y = int(y + 0.5);
			pDC->SetPixel(point_x, point_y, RGB(255, 0, 0));
		}
	}
	if (this->methodtype == 1)
	{
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
		{
			int a, b, d1, d2, d, x, y;
			a = y1 - y2;
			b = x2 - x1;
			d = 2 * a + b;
			d1 = 2 * a;
			d2 = 2 * (a + b);
			x = x1;
			y = y1;
			pDC->SetPixel(x, y, RGB(0, 255, 0));
			while (x < x2)
			{
				if (d < 0)
				{
					x++;
					y++;
					d += d2;
				}
				else
				{
					x++;
					d += d1;
				}
				pDC->SetPixel(x, y, RGB(0, 255, 0));
			}
		}
	}
	if (this->methodtype == 2)
	{
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
		int x, y, dx, dy, e, xs, ys;
		int ​ic = 0;
		dx = abs(x2 - x1);
		dy = abs(y2 - y1);
		float m = (float)(y2 - y1) / (float)(x2 - x1);
		float b = y2 - m * x2;

		if (dx < dy)
		{
			int temp = 0;
			​ic = 1;
			temp = dx;
			dx = dy;
			dy = temp;
		}
		xs = (x2 > x1) ? 1 : -1;
		ys = (y2 > y1) ? 1 : -1;
		x = x1;
		y = y1;
		e = 2 * dy - dx;
		for (int i = 0; i <= dx; i++)
		{
			pDC->SetPixel(x, y, RGB(0, 0, 255));
			if (e > 0)
			{
				e = e - 2 * dx;
				if (​ic) { x += xs; }
				else
				{
					y += ys;
				}
			}
			if (​ic)
			{
				y += ys;
			}
			else
			{
				x += xs;
				e = e + 2 * dy;
			}
		}
	}
}
