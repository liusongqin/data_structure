// my_painting_dlg.cpp: 实现文件
//

#include "pch.h"
#include "Data_structure_practice1_mfc.h"
#include "afxdialogex.h"
#include "my_painting_dlg.h"


// my_painting_dlg 对话框

IMPLEMENT_DYNAMIC(my_painting_dlg, CDialogEx)

my_painting_dlg::my_painting_dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY_PAINTING_DIALOG, pParent)
{

}

my_painting_dlg::~my_painting_dlg()
{
}

void my_painting_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(my_painting_dlg, CDialogEx)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_EXITSIZEMOVE()
	ON_WM_SIZE()
END_MESSAGE_MAP()


// my_painting_dlg 消息处理程序


void my_painting_dlg::ChangeSize(UINT nID, double x, double y)
{
	CWnd* pWnd;
	pWnd = GetDlgItem(nID);
	if (pWnd != NULL) // 判断是否为空，因为在窗口创建的时候也会调用OnSize函数，但是此时各个控件还没有创建，所以pWnd为空
	{
		CRect rec;
		pWnd->GetWindowRect(&rec); // 获取控件变化前的大小
		ScreenToClient(&rec); // 将控件大小转换为在对话框中的区域坐标
		/*index1 = rec.right; index2 = m_rect.Width();
		index1 = index1 * x / index2;
		rec.right = index1;*/
		rec.left = (double)rec.left * x / (double)m_rect.Width(); // 按照比例调整控件的新位置
		rec.top = (double)rec.top * y / (double)m_rect.Height();
		rec.bottom = (double)rec.bottom * y / (double)m_rect.Height();
		rec.right = (double)rec.right * x / (double)m_rect.Width();


		pWnd->MoveWindow(rec); // 伸缩控件
	}
}

void my_painting_dlg::ChangeSize(UINT nID, double x, double y, CRect& t_rect)
{
	CWnd* pWnd;
	pWnd = GetDlgItem(nID);
	if (pWnd != NULL) // 判断是否为空，因为在窗口创建的时候也会调用OnSize函数，但是此时各个控件还没有创建，所以pWnd为空
	{
		CRect rec;
		pWnd->GetWindowRect(&rec); // 获取控件变化前的大小
		ScreenToClient(&rec); // 将控件大小转换为在对话框中的区域坐标
		/*index1 = rec.right; index2 = m_rect.Width();
		index1 = index1 * x / index2;
		rec.right = index1;*/
		rec.left = (double)rec.left * x / (double)t_rect.left; // 按照比例调整控件的新位置
		rec.top = (double)rec.top * y / (double)t_rect.top;
		rec.bottom = (double)rec.bottom * y / (double)t_rect.bottom;
		rec.right = (double)rec.right * x / (double)t_rect.right;


		pWnd->MoveWindow(rec); // 伸缩控件
	}
}

void my_painting_dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnLButtonDown(nFlags, point);
	// 记录当前按下的点

	m_ptPrev = point;
}


void my_painting_dlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnRButtonDown(nFlags, point);
	MessageBox(_T("你点的是右键"), _T("鼠标事件实例"), MB_OK);
}


void my_painting_dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nFlags & MK_LBUTTON)  // 如果左键处于按下状态
	{
		CDC* pDC = GetDC();  // 获取设备环境

		// 绘制直线
		pDC->MoveTo(m_ptPrev);
		pDC->LineTo(point);

		ReleaseDC(pDC);  // 释放设备环境

		// 更新上一次的点
		m_ptPrev = point;
	}
	CDialogEx::OnMouseMove(nFlags, point);
}


void my_painting_dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnLButtonUp(nFlags, point);
	m_bMouseDown = false;
}


BOOL my_painting_dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	GetClientRect(&m_rect); // 获取客户界面的尺寸
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	return false;
	// 异常: OCX 属性页应返回 FALSE
}


void my_painting_dlg::OnExitSizeMove()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDialogEx::OnExitSizeMove();
	//if (nType != SIZE_MINIMIZED) // 如果确定OnInitDialog已经调用完毕
	CRect rec;
	rec.left = (double)m_rect.Width(); // 按照比例调整控件的新位置
	rec.top = (double)m_rect.Height();
	rec.bottom = (double)m_rect.Height();
	rec.right = (double)m_rect.Width();
	GetClientRect(&m_rect);
	HWND hwndChild = ::GetWindow(m_hWnd, GW_CHILD);
	int nID = 0;
	while (hwndChild)
	{
		nID = ::GetDlgCtrlID(hwndChild); // 获取控件ID
		ChangeSize(nID, m_rect.Width(), m_rect.Height(), rec);
		hwndChild = ::GetWindow(hwndChild, GW_HWNDNEXT);

	}
}


void my_painting_dlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
		//正常大小和最大化执行
	if (nType == SIZE_MAXIMIZED) // 如果确定OnInitDialog已经调用完毕
	{

		HWND hwndChild = ::GetWindow(m_hWnd, GW_CHILD);
		int nID = 0;
		while (hwndChild)
		{
			nID = ::GetDlgCtrlID(hwndChild); // 获取控件ID
			ChangeSize(nID, cx, cy);
			hwndChild = ::GetWindow(hwndChild, GW_HWNDNEXT);

		}
		GetClientRect(&m_rect);
		change_index = 1;
	}
	if ((nType == SIZE_RESTORED) && (change_index))
	{
		HWND hwndChild = ::GetWindow(m_hWnd, GW_CHILD);
		int nID = 0;
		while (hwndChild)
		{
			nID = ::GetDlgCtrlID(hwndChild); // 获取控件ID
			ChangeSize(nID, cx, cy);
			hwndChild = ::GetWindow(hwndChild, GW_HWNDNEXT);

		}
		GetClientRect(&m_rect);
		change_index = 0;

	}

}
