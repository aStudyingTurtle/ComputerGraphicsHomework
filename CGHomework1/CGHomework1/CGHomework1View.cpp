// CGHomework1View.cpp: CCGHomework1View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "CGHomework1.h"
#endif

#include "CGHomework1Doc.h"
#include "CGHomework1View.h"
#include "LineEdit.h"
#include "YuanEdit.h"
#include "TuoyuanEdit.h"
#include <cmath>
#include <vector>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <iostream>
#include <Eigen/Core>
using namespace std;
using Eigen::MatrixXd;

// CCGHomework1View

IMPLEMENT_DYNCREATE(CCGHomework1View, CView)

BEGIN_MESSAGE_MAP(CCGHomework1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CCGHomework1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_32775, &CCGHomework1View::On32775)
	ON_COMMAND(ID_32776, &CCGHomework1View::On32776)
	ON_COMMAND(ID_32777, &CCGHomework1View::On32777)
	ON_COMMAND(ID_32778, &CCGHomework1View::On32778)
	ON_COMMAND(ID_32780, &CCGHomework1View::On32780)
	ON_COMMAND(ID_32781, &CCGHomework1View::On32781)
	ON_COMMAND(ID_32783, &CCGHomework1View::On32783)
	ON_COMMAND(ID_32784, &CCGHomework1View::On32784)
	ON_COMMAND(ID_32785, &CCGHomework1View::On32785)
	ON_COMMAND(ID_32787, &CCGHomework1View::On32787)
	ON_COMMAND(ID_32788, &CCGHomework1View::On32788)
	ON_COMMAND(ID_32789, &CCGHomework1View::On32789)
	ON_COMMAND(ID_32790, &CCGHomework1View::On32790)
	ON_COMMAND(ID_32791, &CCGHomework1View::On32791)
	ON_COMMAND(ID_32793, &CCGHomework1View::On32793)
	ON_COMMAND(ID_32794, &CCGHomework1View::On32794)
	ON_COMMAND(ID_32795, &CCGHomework1View::On32795)
	ON_COMMAND(ID_32798, &CCGHomework1View::On32798)
	ON_COMMAND(ID_32799, &CCGHomework1View::On32799)
	ON_COMMAND(ID_32800, &CCGHomework1View::On32800)
	ON_COMMAND(ID_32801, &CCGHomework1View::On32801)
	ON_COMMAND(ID_32802, &CCGHomework1View::On32802)
	ON_COMMAND(ID_32797, &CCGHomework1View::On32797)
END_MESSAGE_MAP()

// CCGHomework1View 构造/析构

CCGHomework1View::CCGHomework1View() noexcept
{
	// TODO: 在此处添加构造代码
}

CCGHomework1View::~CCGHomework1View()
{
}

BOOL CCGHomework1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CCGHomework1View 绘图

void CCGHomework1View::OnDraw(CDC* /*pDC*/)
{
	CCGHomework1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CCGHomework1View 打印


void CCGHomework1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CCGHomework1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CCGHomework1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CCGHomework1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CCGHomework1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CCGHomework1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CCGHomework1View 诊断

#ifdef _DEBUG
void CCGHomework1View::AssertValid() const
{
	CView::AssertValid();
}

void CCGHomework1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCGHomework1Doc* CCGHomework1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCGHomework1Doc)));
	return (CCGHomework1Doc*)m_pDocument;
}
#endif //_DEBUG


// CCGHomework1View 消息处理程序


void CCGHomework1View::On32775()
{
	LineEdit lineEditxy(this, 0);
	lineEditxy.DoModal();
}


void CCGHomework1View::On32776()
{
	// TODO: 在此添加命令处理程序代码
	Invalidate();
}


void CCGHomework1View::On32777()
{
	// TODO: 在此添加命令处理程序代码
	LineEdit lineEditxy(this, 1);
	lineEditxy.DoModal();
}


void CCGHomework1View::On32778()
{
	// TODO: 在此添加命令处理程序代码
	LineEdit lineEditxy(this, 2);
	lineEditxy.DoModal();
}


void CCGHomework1View::On32780()
{
	// TODO: 在此添加命令处理程序代码
	YuanEdit yuanEditXY(this);
	yuanEditXY.DoModal();
}


void CCGHomework1View::On32781()
{
	// TODO: 在此添加命令处理程序代码
	TuoyuanEdit tuoYuanEdit(this);
	tuoYuanEdit.DoModal();
}

class Edge
{
public:
	int ymax;
	float x;
	float dx;
	Edge* next;
};

class Point
{
public:
	int x;
	int y;

	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

void CCGHomework1View::On32783()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = this->GetDC();
	CRect rect;
	GetClientRect(&rect);
	//移动坐标原点到客户区中心
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetViewportOrg(0, 0);
	pDC->SetViewportExt(rect.right, rect.bottom);
	pDC->SetWindowOrg(0, 0);
	pDC->SetWindowExt(1000, 1000);
	//画多边形
	pDC->MoveTo(200, 200);
	pDC->LineTo(800, 350);
	pDC->LineTo(750, 750);
	pDC->LineTo(650, 450);
	pDC->LineTo(200, 350);
	pDC->LineTo(200, 200);
	//填充
	const int windowWidth = 1001;
	const int windowHeight = 1001;
	std::vector<Point> vertices = {Point(200, 200), Point(800, 350), Point(750, 750), Point(650, 450), Point(200, 350)};
	Edge* ET[windowHeight];
	Edge* AET;
	int maxY = 0;
	for (int i = 0; i < vertices.size(); i++)
	{
		if (vertices[i].y > maxY)
		{
			maxY = vertices[i].y;
		}
	}
	Edge* pET[windowHeight];
	for (int i = 0; i < maxY; i++)
	{
		pET[i] = new Edge();
		pET[i]->next = nullptr;
	}
	AET = new Edge();
	AET->next = nullptr;
	for (int i = 0; i < vertices.size(); i++)
	{
		int x0 = vertices[(i - 1 + vertices.size()) % vertices.size()].x;
		int x1 = vertices[i].x;
		int x2 = vertices[(i + 1) % vertices.size()].x;
		int x3 = vertices[(i + 2) % vertices.size()].x;
		int y0 = vertices[(i - 1 + vertices.size()) % vertices.size()].y;
		int y1 = vertices[i].y;
		int y2 = vertices[(i + 1) % vertices.size()].y;
		int y3 = vertices[(i + 2) % vertices.size()].y;
		if (y1 == y2)
			continue;
		int ymin = y1 > y2 ? y2 : y1;
		int ymax = y1 > y2 ? y1 : y2;
		float x = y1 > y2 ? x2 : x1;
		float dx = (x1 - x2) * 1.0f / (y1 - y2);
		if (((y1 < y2) && (y1 > y0)) || ((y2 < y1) && (y2 > y3)))
		{
			ymin++;
			x += dx;
		}
		Edge* p = new Edge();
		p->ymax = ymax;
		p->x = x;
		p->dx = dx;
		p->next = pET[ymin]->next;
		pET[ymin]->next = p;
	}
	for (int i = 0; i < maxY; i++)
	{
		while (pET[i]->next)
		{
			Edge* pInsert = pET[i]->next;
			Edge* p = AET;
			while (p->next)
			{
				if (pInsert->x > p->next->x)
				{
					p = p->next;
					continue;
				}
				if (pInsert->x == p->next->x && pInsert->dx > p->next->dx)
				{
					p = p->next;
					continue;
				}
				break;
			}
			pET[i]->next = pInsert->next;
			pInsert->next = p->next;
			p->next = pInsert;
		}
		Edge* p = AET;
		while (p->next && p->next->next)
		{
			for (int x = p->next->x; x < p->next->next->x; x++)
			{
				pDC->SetPixel(x, i, RGB(255, 0, 0));
			}
			p = p->next->next;
		}
		p = AET;
		while (p->next)
		{
			if (p->next->ymax == i)
			{
				Edge* pDelete = p->next;
				p->next = pDelete->next;
				pDelete->next = nullptr;
				delete pDelete;
			}
			else
			{
				p = p->next;
			}
		}
		p = AET;
		while (p->next)
		{
			p->next->x += p->next->dx;
			p = p->next;
		}
	}
}

void CCGHomework1View::Fill4(CDC* pDC, int x, int y)
{
	COLORREF color = pDC->GetPixel(x, y);
	if (color != RGB(0, 0, 0) && color != RGB(0, 255, 0))
	{
		pDC->SetPixel(x, y, RGB(0, 255, 0));
		CCGHomework1View::Fill4(pDC, x, y - 1);
		CCGHomework1View::Fill4(pDC, x, y + 1);
		CCGHomework1View::Fill4(pDC, x - 1, y);
		CCGHomework1View::Fill4(pDC, x + 1, y);
	}
}

void CCGHomework1View::Fill8(CDC* pDC, int x, int y)
{
	COLORREF color = pDC->GetPixel(x, y);
	// if (color != RGB(0, 0, 0) && color != RGB(0, 255, 0))
	if (color == RGB(255, 255, 255) && pDC->GetPixel(x + 1, y) == RGB(255, 255, 255) && pDC->GetPixel(x - 1, y) ==
		RGB(255, 255, 255) && pDC->GetPixel(x, y + 1) == RGB(255, 255, 255) && pDC->GetPixel(x, y - 1) == RGB(
			255, 255, 255))
	{
		pDC->SetPixel(x, y, RGB(0, 255, 0));
		CCGHomework1View::Fill8(pDC, x, y - 1);
		CCGHomework1View::Fill8(pDC, x, y + 1);
		CCGHomework1View::Fill8(pDC, x - 1, y);
		CCGHomework1View::Fill8(pDC, x + 1, y);
		CCGHomework1View::Fill8(pDC, x + 1, y - 1);
		CCGHomework1View::Fill8(pDC, x - 1, y + 1);
		CCGHomework1View::Fill8(pDC, x - 1, y - 1);
		CCGHomework1View::Fill8(pDC, x + 1, y + 1);
	}
	return;
}

void CCGHomework1View::On32784()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = this->GetDC();
	pDC->SetWindowOrg(0, 0);
	pDC->SetWindowExt(1000, 1000);
	//画多边形
	pDC->MoveTo(200, 200);
	pDC->LineTo(800, 350);
	pDC->LineTo(750, 750);
	pDC->LineTo(650, 450);
	pDC->LineTo(200, 350);
	pDC->LineTo(200, 200);
	//填充
	CCGHomework1View::Fill4(pDC, 250, 250);
}


void CCGHomework1View::On32785()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = this->GetDC();
	pDC->SetWindowOrg(0, 0);
	pDC->SetWindowExt(1000, 1000);
	//画多边形
	pDC->MoveTo(200, 200);
	pDC->LineTo(800, 350);
	pDC->LineTo(750, 750);
	pDC->LineTo(650, 450);
	pDC->LineTo(200, 350);
	pDC->LineTo(200, 200);
	//填充
	CCGHomework1View::Fill8(pDC, 250, 250);
	CCGHomework1View::Fill8(pDC, 300, 300);
}


void CCGHomework1View::On32787()
{
	// TODO: 在此添加控件通知处理程序代码
	CDC* pDC = this->GetDC();
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

	//四边形顶点
	std::vector<Point> vertices = {Point(300, 300), Point(300, 500), Point(500, 400), Point(500, 300), Point(300, 300)};
	pDC->MoveTo(vertices[0].x, vertices[0].y);
	for (int i = 1; i < vertices.size(); i++)
	{
		pDC->LineTo(vertices[i].x, vertices[i].y);
	}
	pDC->LineTo(vertices[0].x, vertices[0].y);

	//平移a,b
	int ax = 200, by = 200;
	Eigen::Matrix3d matrix_i33;
	matrix_i33 << 1, 0, 0, 0, 1, 0, ax, by, 1;
	for (int i = 0; i < vertices.size(); i++)
	{
		Eigen::Vector3d v(vertices[i].x - 500, vertices[i].y - 500, 1);
		v = v.transpose() * matrix_i33;
		vertices[i] = Point(v[0], v[1]);
	}

	// 平移后的图
	pDC->MoveTo(vertices[0].x + 500, vertices[0].y + 500);
	for (int i = 1; i < vertices.size(); i++)
	{
		pDC->LineTo(vertices[i].x + 500, vertices[i].y + 500);
	}
	pDC->LineTo(vertices[0].x + 500, vertices[0].y + 500);
}


void CCGHomework1View::On32788()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = this->GetDC();
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

	//四边形顶点
	std::vector<Point> vertices = {Point(300, 300), Point(300, 500), Point(500, 400), Point(500, 300), Point(300, 300)};
	pDC->MoveTo(vertices[0].x, vertices[0].y);
	for (int i = 1; i < vertices.size(); i++)
	{
		pDC->LineTo(vertices[i].x, vertices[i].y);
	}
	pDC->LineTo(vertices[0].x, vertices[0].y);

	//比例变换a,b
	int ax = 1, by = 2;
	Eigen::Matrix3d matrix_i33;
	matrix_i33 << ax, 0, 0, 0, by, 0, 0, 0, 1;
	for (int i = 0; i < vertices.size(); i++)
	{
		Eigen::Vector3d v(vertices[i].x - 500, vertices[i].y - 500, 1);
		v = v.transpose() * matrix_i33;
		vertices[i] = Point(v[0], v[1]);
	}

	// 变换的图
	pDC->MoveTo(vertices[0].x + 500, vertices[0].y + 500);
	for (int i = 1; i < vertices.size(); i++)
	{
		pDC->LineTo(vertices[i].x + 500, vertices[i].y + 500);
	}
	pDC->LineTo(vertices[0].x + 500, vertices[0].y + 500);
}


void CCGHomework1View::On32789()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = this->GetDC();
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

	//四边形顶点
	std::vector<Point> vertices = {Point(300, 300), Point(300, 500), Point(500, 400), Point(500, 300), Point(300, 300)};
	pDC->MoveTo(vertices[0].x, vertices[0].y);
	for (int i = 1; i < vertices.size(); i++)
	{
		pDC->LineTo(vertices[i].x, vertices[i].y);
	}
	pDC->LineTo(vertices[0].x, vertices[0].y);

	//对称变换a,b,d,e
	int a = 1, b = 0, d = 0, e = -1; //x轴
	Eigen::Matrix3d matrix_i33;
	matrix_i33 << a, d, 0, b, e, 0, 0, 0, 1;
	for (int i = 0; i < vertices.size(); i++)
	{
		Eigen::Vector3d v(vertices[i].x - 500, vertices[i].y - 500, 1);
		v = v.transpose() * matrix_i33;
		vertices[i] = Point(v[0], v[1]);
	}

	// 变换的图
	pDC->MoveTo(vertices[0].x + 500, vertices[0].y + 500);
	for (int i = 1; i < vertices.size(); i++)
	{
		TRACE("%d,%d", vertices[i].x + 500, vertices[i].y + 500);
		pDC->LineTo(vertices[i].x + 500, vertices[i].y + 500);
	}
	pDC->LineTo(vertices[0].x + 500, vertices[0].y + 500);
}


void CCGHomework1View::On32790()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = this->GetDC();
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

	//四边形顶点
	std::vector<Point> vertices = {Point(300, 300), Point(300, 500), Point(500, 400), Point(500, 300), Point(300, 300)};
	pDC->MoveTo(vertices[0].x, vertices[0].y);
	for (int i = 1; i < vertices.size(); i++)
	{
		pDC->LineTo(vertices[i].x, vertices[i].y);
	}
	pDC->LineTo(vertices[0].x, vertices[0].y);

	//错切变换a,b,d,e
	int b = 0, d = 1;
	Eigen::Matrix3d matrix_i33;
	matrix_i33 << 1, d, 0, b, 1, 0, 0, 0, 1;
	for (int i = 0; i < vertices.size(); i++)
	{
		Eigen::Vector3d v(vertices[i].x - 500, vertices[i].y - 500, 1);
		v = v.transpose() * matrix_i33;
		vertices[i] = Point(v[0], v[1]);
	}

	// 变换的图
	pDC->MoveTo(vertices[0].x + 500, vertices[0].y + 500);
	for (int i = 1; i < vertices.size(); i++)
	{
		TRACE("%d,%d", vertices[i].x + 500, vertices[i].y + 500);
		pDC->LineTo(vertices[i].x + 500, vertices[i].y + 500);
	}
	pDC->LineTo(vertices[0].x + 500, vertices[0].y + 500);
}


void CCGHomework1View::On32791()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = this->GetDC();
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

	//四边形顶点
	std::vector<Point> vertices = {Point(300, 300), Point(300, 500), Point(500, 400), Point(500, 300), Point(300, 300)};
	pDC->MoveTo(vertices[0].x, vertices[0].y);
	for (int i = 1; i < vertices.size(); i++)
	{
		pDC->LineTo(vertices[i].x, vertices[i].y);
	}
	pDC->LineTo(vertices[0].x, vertices[0].y);

	//旋转变换 seita角度
	double seita = 60;
	seita = 3.1415926535897 * seita / 180;
	Eigen::Matrix3d matrix_i33;
	matrix_i33 << cos(seita), sin(seita), 0, -sin(seita), cos(seita), 0, 0, 0, 1;
	for (int i = 0; i < vertices.size(); i++)
	{
		Eigen::Vector3d v(double(vertices[i].x - 500), double(vertices[i].y - 500), 1);
		v = v.transpose() * matrix_i33;
		vertices[i] = Point(int(v[0]), int(v[1]));
	}

	// 变换的图
	pDC->MoveTo(vertices[0].x + 500, vertices[0].y + 500);
	for (int i = 1; i < vertices.size(); i++)
	{
		TRACE("%d,%d", vertices[i].x + 500, vertices[i].y + 500);
		pDC->LineTo(vertices[i].x + 500, vertices[i].y + 500);
	}
	pDC->LineTo(vertices[0].x + 500, vertices[0].y + 500);
}


void CCGHomework1View::On32793()
{
	// TODO: 在此添加命令处理程序代码
}


void CCGHomework1View::On32794()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = this->GetDC();
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
	//画屏幕
	pDC->MoveTo(200, 200);
	pDC->LineTo(200, 400);
	pDC->LineTo(400, 400);
	pDC->LineTo(400, 200);
	pDC->LineTo(200, 200);
	//裁剪(100,100) (350,350)
	float x1 = 100, y1 = 100, x2 = 350, y2 = 350;
	int Left = 1, Right = 2, Bottom = 4, Top = 8, xl = 200, xr = 400, yb = 200, yt = 400;
	int code1, code2, code;
	float x, y;
	int c = 0;
	if (x1 < xl)c = c | Left;
	if (x1 > xr)c = c | Right;
	if (y1 < yb)c = c | Bottom;
	if (y1 > yt)c = c | Top;
	code1 = c;
	c = 0;
	if (x2 < xl)c = c | Left;
	if (x2 > xr)c = c | Right;
	if (y2 < yb)c = c | Bottom;
	if (y2 > yt)c = c | Top;
	code2 = c;
	while (code1 != 0 || code2 != 0)
	{
		if (code1 && code2 != 0)return;
		if (code1 != 0)code = code1;
		else code = code2;
		if ((Left & code) != 0)
		{
			x = xl;
			y = y1 + (y2 - y1) * (xl - x1) / (x2 - x1);
		}
		else if ((Right & code) != 0)
		{
			x = xr;
			y = y1 + (y2 - y1) * (xr - x1) / (x2 - x1);
		}
		else if ((Bottom & code) != 0)
		{
			y = yb;
			x = xl + (x2 - x1) * (yb - y1) / (y2 - y1);
		}
		else if ((Top & code) != 0)
		{
			y = yt;
			x = xl + (x2 - x1) * (yt - y1) / (y2 - y1);
		}
		if (code == code1)
		{
			x1 = x;
			y1 = y;
			int c = 0;
			if (x < xl)c = c | Left;
			if (x > xr)c = c | Right;
			if (y < yb)c = c | Bottom;
			if (y > yt)c = c | Top;
			code1 = c;
		}
		else
		{
			x2 = x;
			y2 = y;
			int c = 0;
			if (x < xl)c = c | Left;
			if (x > xr)c = c | Right;
			if (y < yb)c = c | Bottom;
			if (y > yt)c = c | Top;
			code2 = c;
		}
	}
	pDC->MoveTo(x1, y1);
	pDC->LineTo(x2, y2);
}

/*
 *
 *下面是多边形裁剪
 *这事一条华丽的分割线
 *
 */

int result[6][2] = {{110, 50}, {250, 400}, {400, 60}, {540, 400}, {500, 150}, {500, 50}};
int re[4][2] = {{100, 600}, {600, 100}, {600, 100}, {100, 100}};

enum mark { L, B, R, T };

struct P
{
	int x;
	int y;
	int judge;
};

struct node
{
	int data[2];
	int judge;
	node* next;
	node* pre;
};

void addNode(node*& now, int num1, int num2, int ju)
{
	node* p = now;
	node* q = NULL;
	q = new node;
	q->data[0] = num1;
	q->data[1] = num2;
	q->judge = ju;
	q->pre = p;
	p->next = q;
	now = q;
}

void insertNode(node*& one, node*& two, const P Three, bool change)
{
	node* tem = new node;
	tem = new node;
	tem->data[0] = Three.x;
	tem->data[1] = Three.y;
	tem->judge = Three.judge;
	tem->next = two;
	two->pre = tem;
	tem->pre = one;
	one->next = tem;
	if (change)
	{
		two = tem;
	}
	else
	{
		one = tem;
	}
}

void initNode(node*& head, node*& rec)
{
	head = new node;
	rec = new node;
	head->data[0] = rec->data[0] = 0;
	head->data[1] = rec->data[1] = 0;
	head->next = rec->next = NULL;
	head->pre = rec->pre = NULL;
	node* p = head;
	for (int i = 0; i < 6; ++i)
	{
		addNode(p, result[i][0], result[i][1], 0);
	}
	p->next = head;
	head->pre = p;
	p = rec;
	for (int i = 0; i < 4; ++i)
	{
		addNode(p, re[i][0], re[i][1], 0);
	}
	p->next = rec;
	rec->pre = p;
}

int cross(const node* one, const node* two, const int edg)
{
	int result = 0;
	switch (edg)
	{
	case T:
		if ((one->data[1] > 600) && (two->data[1] < 600) || (one->data[1] < 600) && (two->data[1] > 600))
		{
			result = 1;
		}
		break;
	case R:
		if ((one->data[0] > 600) && (two->data[0] < 600) || (one->data[0] < 600) && (two->data[0] > 600))
		{
			result = 1;
		}
		break;
	case B:
		if ((one->data[1] > 100) && (two->data[1] < 100) || (one->data[1] < 100) && (two->data[1] > 100))
		{
			result = 1;
		}
		break;
	case L:
		if ((one->data[0] > 100) && (two->data[0] < 100) || (one->data[0] < 100) && (two->data[0] > 100))
		{
			result = 1;
		}
		break;
	default:
		break;
	}
	return result;
}

void testPoint(vector<P>& Three, node*& first, node*& head, int edg, float xl, float xr, float yb, float yt)
{
	node* p = first;
	node* q = p->next;
	P tem;
	while (p != head)
	{
		int x = 0;
		int y = 0;
		if (q == head)
		{
			q = q->next;
		}
		float k = 0;
		if (q->data[0] - p->data[0] != 0)
		{
			k = (q->data[1] - p->data[1]) * 1.0 / (q->data[0] - p->data[0]);
		}
		switch (edg)
		{
		case L:
			if (cross(p, q, L))
			{
				x = xl;
				y = p->data[1] + (x - p->data[0]) * k;
				tem.x = x;
				tem.y = y;
				tem.judge = 1;
				Three.push_back(tem);
			}
			break;
		case R:
			if (cross(p, q, R))
			{
				x = xr;
				y = p->data[1] + (x - p->data[0]) * k;
				tem.x = x;
				tem.y = y;
				tem.judge = 1;
				Three.push_back(tem);
			}
			break;
		case B:
			if (cross(p, q, B))
			{
				if (k == 0)
				{
					if (p->data[1] != q->data[1])
					{
						y = yb;
						x = p->data[0];
					}
					else
					{
						break;
					}
				}
				if (k != 0)
				{
					y = yb;
					x = p->data[0] + (y - p->data[1]) / k;
				}
				tem.x = x;
				tem.y = y;
				tem.judge = 1;
				Three.push_back(tem);
			}
			break;
		case T:
			if (cross(p, q, T))
			{
				if (k == 0)
				{
					if (p->data[1] != q->data[1])
					{
						y = yb;
						x = p->data[0];
					}
					else
					{
						break;
					}
				}
				if (k != 0)
				{
					y = yt;
					x = p->data[0] + (y - p->data[1]) / k;
				}
				tem.x = x;
				tem.y = y;
				tem.judge = 1;
				Three.push_back(tem);
			}
			break;
		default:
			break;
		}
		p = p->next;
		q = p->next;
	}
}

void getPoint(vector<P>& Three, node*& head, float xl, float xr, float yb, float yt)
{
	node* p = head->next;
	for (int i = 0; i < 4; ++i)
	{
		testPoint(Three, p, head, i, xl, xr, yb, yt);
	}
}

void sortPointRec(const vector<P> Three, node*& recPoint, int num)
{
	node* p = recPoint->next;
	node* q = p->next;
	bool change = false;
	if (Three[0].y == 100)
	{
		change = true;
	}
	if (num == 2)
	{
		change = false;
	}
	for (int i = 0; i < Three.size(); ++i)
	{
		if (q == recPoint)
		{
			q = q->next;
		}
		if (Three[i].y == 600)
		{
			if ((Three[i].x <= q->data[0] && (q->data[1] == 120)) || (Three[i].x <= q->data[0] && cross(q, p, T)))
			{
				insertNode(p, q, Three[i], change);
			}
			else
			{
				p = p->next;
				q = p->next;
				i--;
			}
		}
		else if (Three[i].x == 600)
		{
			if ((Three[i].y >= q->data[1] && (q->data[0] == 120)) || (Three[i].y > p->data[1] && cross(p, q, R)))
			{
				insertNode(p, q, Three[i], change);
			}
			else
			{
				p = p->next;
				q = p->next;
				i--;
			}
		}
		else if (Three[i].y == 100)
		{
			if ((Three[i].x <= p->data[0] && (p->data[1] == 100)) || (Three[i].x <= q->data[0] && cross(p, q, B)))
			{
				insertNode(p, q, Three[i], change);
			}
			else
			{
				p = p->next;
				q = p->next;
				i--;
			}
		}
		else if (Three[i].x == 100)
		{
			if ((Three[i].y <= p->data[1] && (p->data[0] == 100)) || (Three[i].y >= q->data[1] && cross(p, q, L)))
			{
				insertNode(p, q, Three[i], change);
			}
			else
			{
				p = p->next;
				q = p->next;
				i--;
			}
		}
	}
}

void getArray(node*& polPoint, const vector<P> Three, node*& recPoint)
{
	sortPointRec(Three, recPoint, 1);
	sortPointRec(Three, polPoint, 2);
}

void CCGHomework1View::On32795()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = this->GetDC();
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
	//画屏幕
	pDC->MoveTo(100, 100);
	pDC->LineTo(100, 600);
	pDC->LineTo(600, 600);
	pDC->LineTo(600, 100);
	pDC->LineTo(100, 100);

	node* h = new node;
	node* recPoint = new node;
	initNode(h, recPoint);
	vector<P> Three;
	getPoint(Three, h, 100, 600, 100, 600);
	Three[1].judge = 2;
	Three[3].judge = 2;
	getArray(h, Three, recPoint);

	//绘制新的图形
	node* polPoint = h;
	vector<P> Q, S;
	node* one = polPoint->next;
	node* two = recPoint->next;
	P tem;
	int c = 1;
	bool f = false, begin = true;

	while (c != 0)
	{
		if (one->judge == 1)
		{
			tem.x = one->data[0];
			tem.y = one->data[1];
			tem.judge = 0;
			one->judge = 0;
			S.push_back(tem);
			f = true;
		}
		if (f)
		{
			tem.x = one->data[0];
			tem.y = one->data[1];
			tem.judge = 0;
			Q.push_back(tem);
		}
		if (one->judge == 2)
		{
			f = false;
			while ((two->data[0] != one->data[0]) && (two->data[1] != one->data[1]))
			{
				two = two->next;
			}
			while ((two->data[0] != S[0].x) && (two->data[1] != S[0].y))
			{
				if (two != recPoint)
				{
					tem.x = one->data[0];
					tem.y = one->data[1];
					tem.judge = 0;
					Q.push_back(tem);
				}
				two = two->next;
			}
			two = recPoint->next;
			//输出绘制
			for (int i = 0; i < Q.size(); ++i)
			{
				pDC->LineTo(Q[i].x, Q[i].y);
			}
			Q.clear();
			S.clear();

			node* ma = polPoint->next; //检测是否有入点标记的点存在
			c = 0;
			while (ma != polPoint)
			{
				if (ma->judge == 1)
				{
					c++;
				}
				ma = ma->next;
			}
		}
		one = one->next;
		if (one == polPoint)
		{
			one = one->next;
		}
	}
}

/*
 *又是一条分割线
 *之后的都是三维的了
 */
Point Transform3Dto2D(int x, int y, int z)
{
	x = int(x - (z * cos(0.785398163)) / 2);
	y = int(y - (z * sin(0.785398163)) / 2);
	return Point(x, y);
}

void CCGHomework1View::On32798()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = this->GetDC();
	CRect rect;
	GetClientRect(&rect);
	//移动坐标原点到客户区中心
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetViewportOrg(0, 0);
	pDC->SetViewportExt(rect.right, rect.bottom);
	pDC->SetWindowOrg(0, 0);
	pDC->SetWindowExt(1000, 1000);
	std::vector<Point> vertices_di = {
		Point(100, 100), Point(100, 300), Point(300, 300), Point(300, 100), Point(100, 100)
	};
	std::vector<Point> vertices_new_di = {
		Point(100, 100), Point(100, 300), Point(300, 300), Point(300, 100), Point(100, 100)
	};
	std::vector<Point> vertices_new_shang = {
		Point(100, 100), Point(100, 300), Point(300, 300), Point(300, 100), Point(100, 100)
	};
	//画立方体
	pDC->MoveTo(Transform3Dto2D(vertices_di[0].x, vertices_di[0].y, 0).x,
	            Transform3Dto2D(vertices_di[0].x, vertices_di[0].y, 0).y);
	int i;
	for (i = 0; i < vertices_di.size(); i++)
	{
		pDC->LineTo(Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 0).x,
		            Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 0).y);
	}
	pDC->MoveTo(Transform3Dto2D(vertices_di[0].x, vertices_di[0].y, 100).x,
	            Transform3Dto2D(vertices_di[0].x, vertices_di[0].y, 100).y);
	for (i = 0; i < vertices_di.size(); i++)
	{
		pDC->LineTo(Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 100).x,
		            Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 100).y);
	}
	pDC->MoveTo(Transform3Dto2D(vertices_di[0].x, vertices_di[0].y, 0).x,
	            Transform3Dto2D(vertices_di[0].x, vertices_di[0].y, 100).y);
	for (i = 0; i < vertices_di.size(); i++)
	{
		pDC->MoveTo(Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 0).x,
		            Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 0).y);
		pDC->LineTo(Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 100).x,
		            Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 100).y);
	}
	//平移100 100 100
	int b = 0, d = 1;
	Eigen::Matrix4d matrix_i44;
	matrix_i44 << 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 400, 400, 400, 1;
	for (int i = 0; i < vertices_di.size(); i++)
	{
		Eigen::Vector4d v(vertices_di[i].x - 500, vertices_di[i].y - 500, 0 - 500, 1);
		v = v.transpose() * matrix_i44;
		vertices_new_di[i] = Transform3Dto2D(v[0] + 500, v[1] + 500, v[2] + 500);
		Eigen::Vector4d v1(vertices_di[i].x - 500, vertices_di[i].y - 500, 100 - 500, 1);
		v1 = v1.transpose() * matrix_i44;
		vertices_new_shang[i] = Transform3Dto2D(v1[0] + 500, v1[1] + 500, v1[2] + 500);
	}
	pDC->MoveTo(vertices_new_shang[0].x, vertices_new_shang[0].y);
	for (i = 0; i < vertices_di.size(); i++)
	{
		pDC->LineTo(vertices_new_shang[i].x, vertices_new_shang[i].y);
	}
	pDC->MoveTo(vertices_new_di[0].x, vertices_new_di[0].y);
	for (i = 0; i < vertices_di.size(); i++)
	{
		pDC->LineTo(vertices_new_di[i].x, vertices_new_di[i].y);
	}
	for (i = 0; i < vertices_di.size(); i++)
	{
		pDC->MoveTo(vertices_new_di[i].x, vertices_new_di[i].y);
		pDC->LineTo(vertices_new_shang[i].x, vertices_new_shang[i].y);
	}
}


void CCGHomework1View::On32799()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = this->GetDC();
	CRect rect;
	GetClientRect(&rect);
	//移动坐标原点到客户区中心
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetViewportOrg(0, 0);
	pDC->SetViewportExt(rect.right, rect.bottom);
	pDC->SetWindowOrg(0, 0);
	pDC->SetWindowExt(1000, 1000);
	std::vector<Point> vertices_di = {
		Point(100, 100), Point(100, 300), Point(300, 300), Point(300, 100), Point(100, 100)
	};
	std::vector<Point> vertices_new_di = {
		Point(100, 100), Point(100, 300), Point(300, 300), Point(300, 100), Point(100, 100)
	};
	std::vector<Point> vertices_new_shang = {
		Point(100, 100), Point(100, 300), Point(300, 300), Point(300, 100), Point(100, 100)
	};
	//画立方体
	pDC->MoveTo(Transform3Dto2D(vertices_di[0].x, vertices_di[0].y, 0).x,
	            Transform3Dto2D(vertices_di[0].x, vertices_di[0].y, 0).y);
	int i;
	for (i = 0; i < vertices_di.size(); i++)
	{
		pDC->LineTo(Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 0).x,
		            Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 0).y);
	}
	pDC->MoveTo(Transform3Dto2D(vertices_di[0].x, vertices_di[0].y, 100).x,
	            Transform3Dto2D(vertices_di[0].x, vertices_di[0].y, 100).y);
	for (i = 0; i < vertices_di.size(); i++)
	{
		pDC->LineTo(Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 100).x,
		            Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 100).y);
	}
	pDC->MoveTo(Transform3Dto2D(vertices_di[0].x, vertices_di[0].y, 0).x,
	            Transform3Dto2D(vertices_di[0].x, vertices_di[0].y, 100).y);
	for (i = 0; i < vertices_di.size(); i++)
	{
		pDC->MoveTo(Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 0).x,
		            Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 0).y);
		pDC->LineTo(Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 100).x,
		            Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 100).y);
	}
	//比例0.5 0.5 0.5
	int b = 0, d = 1;
	Eigen::Matrix4d matrix_i44;
	matrix_i44 << 0.5, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 1;
	for (int i = 0; i < vertices_di.size(); i++)
	{
		Eigen::Vector4d v(vertices_di[i].x - 500, vertices_di[i].y - 500, 0 - 500, 1);
		v = v.transpose() * matrix_i44;
		vertices_new_di[i] = Transform3Dto2D(v[0] + 500, v[1] + 500, v[2] + 500);
		Eigen::Vector4d v1(vertices_di[i].x - 500, vertices_di[i].y - 500, 100 - 500, 1);
		v1 = v1.transpose() * matrix_i44;
		vertices_new_shang[i] = Transform3Dto2D(v1[0] + 500, v1[1] + 500, v1[2] + 500);
	}
	pDC->MoveTo(vertices_new_shang[0].x, vertices_new_shang[0].y);
	for (i = 0; i < vertices_di.size(); i++)
	{
		pDC->LineTo(vertices_new_shang[i].x, vertices_new_shang[i].y);
	}
	pDC->MoveTo(vertices_new_di[0].x, vertices_new_di[0].y);
	for (i = 0; i < vertices_di.size(); i++)
	{
		pDC->LineTo(vertices_new_di[i].x, vertices_new_di[i].y);
	}
	for (i = 0; i < vertices_di.size(); i++)
	{
		pDC->MoveTo(vertices_new_di[i].x, vertices_new_di[i].y);
		pDC->LineTo(vertices_new_shang[i].x, vertices_new_shang[i].y);
	}
}


void CCGHomework1View::On32800()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = this->GetDC();
	CRect rect;
	GetClientRect(&rect);
	//移动坐标原点到客户区中心
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetViewportOrg(0, 0);
	pDC->SetViewportExt(rect.right, rect.bottom);
	pDC->SetWindowOrg(0, 0);
	pDC->SetWindowExt(1000, 1000);
	std::vector<Point> vertices_di = {
		Point(100, 100), Point(100, 300), Point(300, 300), Point(300, 100), Point(100, 100)
	};
	std::vector<Point> vertices_new_di = {
		Point(100, 100), Point(100, 300), Point(300, 300), Point(300, 100), Point(100, 100)
	};
	std::vector<Point> vertices_new_shang = {
		Point(100, 100), Point(100, 300), Point(300, 300), Point(300, 100), Point(100, 100)
	};
	//画立方体
	pDC->MoveTo(Transform3Dto2D(vertices_di[0].x, vertices_di[0].y, 0).x,
	            Transform3Dto2D(vertices_di[0].x, vertices_di[0].y, 0).y);
	int i;
	for (i = 0; i < vertices_di.size(); i++)
	{
		pDC->LineTo(Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 0).x,
		            Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 0).y);
	}
	pDC->MoveTo(Transform3Dto2D(vertices_di[0].x, vertices_di[0].y, 100).x,
	            Transform3Dto2D(vertices_di[0].x, vertices_di[0].y, 100).y);
	for (i = 0; i < vertices_di.size(); i++)
	{
		pDC->LineTo(Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 100).x,
		            Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 100).y);
	}
	pDC->MoveTo(Transform3Dto2D(vertices_di[0].x, vertices_di[0].y, 0).x,
	            Transform3Dto2D(vertices_di[0].x, vertices_di[0].y, 100).y);
	for (i = 0; i < vertices_di.size(); i++)
	{
		pDC->MoveTo(Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 0).x,
		            Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 0).y);
		pDC->LineTo(Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 100).x,
		            Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 100).y);
	}
	//绕z旋转60度 
	int b = 0, d = 1;
	Eigen::Matrix4d matrix_i44;
	matrix_i44 << cos(1.0471975511965976), sin(1.0471975511965976), 0, 0, -sin(1.0471975511965976),
		cos(1.0471975511965976), 0, 0, 0, 0, 1, 0, 0, 0, 0, 1;
	for (int i = 0; i < vertices_di.size(); i++)
	{
		Eigen::Vector4d v(vertices_di[i].x - 500, vertices_di[i].y - 500, 0 - 500, 1);
		v = v.transpose() * matrix_i44;
		vertices_new_di[i] = Transform3Dto2D(v[0] + 500, v[1] + 500, v[2] + 500);
		Eigen::Vector4d v1(vertices_di[i].x - 500, vertices_di[i].y - 500, 100 - 500, 1);
		v1 = v1.transpose() * matrix_i44;
		vertices_new_shang[i] = Transform3Dto2D(v1[0] + 500, v1[1] + 500, v1[2] + 500);
	}
	pDC->MoveTo(vertices_new_shang[0].x, vertices_new_shang[0].y);
	for (i = 0; i < vertices_di.size(); i++)
	{
		pDC->LineTo(vertices_new_shang[i].x, vertices_new_shang[i].y);
	}
	pDC->MoveTo(vertices_new_di[0].x, vertices_new_di[0].y);
	for (i = 0; i < vertices_di.size(); i++)
	{
		pDC->LineTo(vertices_new_di[i].x, vertices_new_di[i].y);
	}
	for (i = 0; i < vertices_di.size(); i++)
	{
		pDC->MoveTo(vertices_new_di[i].x, vertices_new_di[i].y);
		pDC->LineTo(vertices_new_shang[i].x, vertices_new_shang[i].y);
	}
}


void CCGHomework1View::On32801()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = this->GetDC();
	CRect rect;
	GetClientRect(&rect);
	//移动坐标原点到客户区中心
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetViewportOrg(0, 0);
	pDC->SetViewportExt(rect.right, rect.bottom);
	pDC->SetWindowOrg(0, 0);
	pDC->SetWindowExt(1000, 1000);
	std::vector<Point> vertices_di = {
		Point(100, 100), Point(100, 300), Point(300, 300), Point(300, 100), Point(100, 100)
	};
	std::vector<Point> vertices_new_di = {
		Point(100, 100), Point(100, 300), Point(300, 300), Point(300, 100), Point(100, 100)
	};
	std::vector<Point> vertices_new_shang = {
		Point(100, 100), Point(100, 300), Point(300, 300), Point(300, 100), Point(100, 100)
	};
	//画立方体
	pDC->MoveTo(Transform3Dto2D(vertices_di[0].x, vertices_di[0].y, 0).x,
	            Transform3Dto2D(vertices_di[0].x, vertices_di[0].y, 0).y);
	int i;
	for (i = 0; i < vertices_di.size(); i++)
	{
		pDC->LineTo(Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 0).x,
		            Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 0).y);
	}
	pDC->MoveTo(Transform3Dto2D(vertices_di[0].x, vertices_di[0].y, 100).x,
	            Transform3Dto2D(vertices_di[0].x, vertices_di[0].y, 100).y);
	for (i = 0; i < vertices_di.size(); i++)
	{
		pDC->LineTo(Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 100).x,
		            Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 100).y);
	}
	pDC->MoveTo(Transform3Dto2D(vertices_di[0].x, vertices_di[0].y, 0).x,
	            Transform3Dto2D(vertices_di[0].x, vertices_di[0].y, 100).y);
	for (i = 0; i < vertices_di.size(); i++)
	{
		pDC->MoveTo(Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 0).x,
		            Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 0).y);
		pDC->LineTo(Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 100).x,
		            Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 100).y);
	}
	//zox对称
	int b = 0, d = 1;
	Eigen::Matrix4d matrix_i44;
	matrix_i44 << 1, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1;
	for (int i = 0; i < vertices_di.size(); i++)
	{
		Eigen::Vector4d v(vertices_di[i].x - 500, vertices_di[i].y - 500, 0 - 500, 1);
		v = v.transpose() * matrix_i44;
		vertices_new_di[i] = Transform3Dto2D(v[0] + 500, v[1] + 500, v[2] + 500);
		Eigen::Vector4d v1(vertices_di[i].x - 500, vertices_di[i].y - 500, 100 - 500, 1);
		v1 = v1.transpose() * matrix_i44;
		vertices_new_shang[i] = Transform3Dto2D(v1[0] + 500, v1[1] + 500, v1[2] + 500);
	}
	pDC->MoveTo(vertices_new_shang[0].x, vertices_new_shang[0].y);
	for (i = 0; i < vertices_di.size(); i++)
	{
		pDC->LineTo(vertices_new_shang[i].x, vertices_new_shang[i].y);
	}
	pDC->MoveTo(vertices_new_di[0].x, vertices_new_di[0].y);
	for (i = 0; i < vertices_di.size(); i++)
	{
		pDC->LineTo(vertices_new_di[i].x, vertices_new_di[i].y);
	}
	for (i = 0; i < vertices_di.size(); i++)
	{
		pDC->MoveTo(vertices_new_di[i].x, vertices_new_di[i].y);
		pDC->LineTo(vertices_new_shang[i].x, vertices_new_shang[i].y);
	}
}


void CCGHomework1View::On32802()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = this->GetDC();
	CRect rect;
	GetClientRect(&rect);
	//移动坐标原点到客户区中心
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetViewportOrg(0, 0);
	pDC->SetViewportExt(rect.right, rect.bottom);
	pDC->SetWindowOrg(0, 0);
	pDC->SetWindowExt(1000, 1000);
	//z分别为0和100
	std::vector<Point> vertices_di = {
		Point(100, 100), Point(100, 300), Point(300, 300), Point(300, 100), Point(100, 100)
	};
	std::vector<Point> vertices_new_di = {
		Point(100, 100), Point(100, 300), Point(300, 300), Point(300, 100), Point(100, 100)
	};
	std::vector<Point> vertices_new_shang = {
		Point(100, 100), Point(100, 300), Point(300, 300), Point(300, 100), Point(100, 100)
	};
	//画立方体
	pDC->MoveTo(Transform3Dto2D(vertices_di[0].x, vertices_di[0].y, 0).x,
	            Transform3Dto2D(vertices_di[0].x, vertices_di[0].y, 0).y);
	int i;
	for (i = 0; i < vertices_di.size(); i++)
	{
		pDC->LineTo(Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 0).x,
		            Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 0).y);
	}
	pDC->MoveTo(Transform3Dto2D(vertices_di[0].x, vertices_di[0].y, 100).x,
	            Transform3Dto2D(vertices_di[0].x, vertices_di[0].y, 100).y);
	for (i = 0; i < vertices_di.size(); i++)
	{
		pDC->LineTo(Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 100).x,
		            Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 100).y);
	}
	pDC->MoveTo(Transform3Dto2D(vertices_di[0].x, vertices_di[0].y, 0).x,
	            Transform3Dto2D(vertices_di[0].x, vertices_di[0].y, 100).y);
	for (i = 0; i < vertices_di.size(); i++)
	{
		pDC->MoveTo(Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 0).x,
		            Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 0).y);
		pDC->LineTo(Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 100).x,
		            Transform3Dto2D(vertices_di[i].x, vertices_di[i].y, 100).y);
	}
	//沿x错切 0.1
	int b = 0, d = 1;
	Eigen::Matrix4d matrix_i44;
	matrix_i44 << 1, 0, 0, 0, 0.1, 1, 0, 0.1, 0, 0, 1, 0, 0, 0, 0, 1;
	for (int i = 0; i < vertices_di.size(); i++)
	{
		Eigen::Vector4d v(vertices_di[i].x - 500, vertices_di[i].y - 500, 0 - 500, 1);
		v = v.transpose() * matrix_i44;
		vertices_new_di[i] = Transform3Dto2D(v[0] + 500, v[1] + 500, v[2] + 500);
		Eigen::Vector4d v1(vertices_di[i].x - 500, vertices_di[i].y - 500, 100 - 500, 1);
		v1 = v1.transpose() * matrix_i44;
		vertices_new_shang[i] = Transform3Dto2D(v1[0] + 500, v1[1] + 500, v1[2] + 500);
	}
	pDC->MoveTo(vertices_new_shang[0].x, vertices_new_shang[0].y);
	for (i = 0; i < vertices_di.size(); i++)
	{
		pDC->LineTo(vertices_new_shang[i].x, vertices_new_shang[i].y);
	}
	pDC->MoveTo(vertices_new_di[0].x, vertices_new_di[0].y);
	for (i = 0; i < vertices_di.size(); i++)
	{
		pDC->LineTo(vertices_new_di[i].x, vertices_new_di[i].y);
	}
	for (i = 0; i < vertices_di.size(); i++)
	{
		pDC->MoveTo(vertices_new_di[i].x, vertices_new_di[i].y);
		pDC->LineTo(vertices_new_shang[i].x, vertices_new_shang[i].y);
	}
}


void CCGHomework1View::On32797()
{
	// TODO: 在此添加命令处理程序代码
	CDC* pDC = this->GetDC();
	CRect rect;
	GetClientRect(&rect);
	//移动坐标原点到客户区中心
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetViewportOrg(0, 0);
	pDC->SetViewportExt(rect.right, rect.bottom);
	pDC->SetWindowOrg(0, 0);
	pDC->SetWindowExt(1000, 1000);
	//z分别为0和100
	std::vector<Eigen::Vector3d> vertices_di = {
		Eigen::Vector3d(100, 100, 0), Eigen::Vector3d(100, 300, 0), Eigen::Vector3d(300, 300, 0),
		Eigen::Vector3d(300, 100, 0), Eigen::Vector3d(100, 100, 0),
		Eigen::Vector3d(100, 100, 100), Eigen::Vector3d(100, 300, 100), Eigen::Vector3d(300, 300, 100),
		Eigen::Vector3d(300, 100, 100)
	};
	std::vector<Point> vertices_tmp;
	//主视图
	vertices_tmp.clear();
	Eigen::Matrix4d matrix_i44;
	matrix_i44 << 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1;
	for (int i = 0; i < vertices_di.size(); i++)
	{
		Eigen::Vector4d v(vertices_di[i][0] - 500, vertices_di[i][1] - 500, vertices_di[i][2] - 500, 1);
		v = v.transpose() * matrix_i44;
		vertices_tmp.push_back(Transform3Dto2D(v[0] + 500, v[1] + 500, v[2] + 500));
	}
	pDC->MoveTo(vertices_tmp[0].x, vertices_tmp[0].y);
	for (int i = 0; i < vertices_di.size(); i++)
	{
		pDC->LineTo(vertices_tmp[i].x, vertices_tmp[i].y);
	}
	pDC->LineTo(vertices_tmp[2].x, vertices_tmp[2].y);
	//左视图
	vertices_tmp.clear();
	Eigen::Matrix4d matrix_i441;
	matrix_i441 << 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 1, 0, -100, 0, 0, 1;
	for (int i = 0; i < vertices_di.size(); i++)
	{
		Eigen::Vector4d v(vertices_di[i][0] - 500, vertices_di[i][1] - 500, vertices_di[i][2] - 500, 1);
		v = v.transpose() * matrix_i441;
		vertices_tmp.push_back(Transform3Dto2D(v[0] + 500, v[1] + 500, v[2] + 500));
	}
	pDC->MoveTo(vertices_tmp[0].x, vertices_tmp[0].y);
	for (int i = 0; i < vertices_di.size() - 1; i++)
	{
		pDC->LineTo(vertices_tmp[i].x, vertices_tmp[i].y);
	}
	pDC->LineTo(vertices_tmp[1].x, vertices_tmp[1].y);
	//俯视图
	vertices_tmp.clear();
	Eigen::Matrix4d matrix_i442;
	matrix_i442 << 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1;
	for (int i = 0; i < vertices_di.size(); i++)
	{
		Eigen::Vector4d v(vertices_di[i][0] - 500, vertices_di[i][1] - 500, vertices_di[i][2] - 500, 1);
		v = v.transpose() * matrix_i442;
		vertices_tmp.push_back(Transform3Dto2D(v[0] + 500, v[1] + 500, v[2] + 500));
	}
	pDC->MoveTo(vertices_tmp[1].x + 400, vertices_tmp[1].y + 400);
	for (int i = 1; i < vertices_di.size(); i++)
	{
		pDC->LineTo(vertices_tmp[i].x + 400, vertices_tmp[i].y + 400);
	}
}
