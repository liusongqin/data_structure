
// Data_structure_practice1_mfcDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Data_structure_practice1_mfc.h"
#include "Data_structure_practice1_mfcDlg.h"
#include "afxdialogex.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include<stdlib.h>
#include<string>
#include<sstream>
#include "del_dlg.h"
#include "ini_dialog.h"
#include"add_dlg.h"
#include"insert_dlg.h"
#include "error_dlg.h"
#include "del_num_dlg.h"
#include "ini_mylist_dlg.h"
#include "insert_accord_number_dlg.h"
#include "help_dlg.h"
#include "my_about_dlg.h"
#include "my_parenthesis_match_dlg.h"
#include "my_painting_dlg.h"


std::string ptr_to_HexNumber(ListNode* ptr)
{
	std::stringstream ss;
	ss << std::hex << ptr;
	std::string hexNumber = ss.str();
	return hexNumber;
}

//在“my_parenthesis_match_dlg.h”已经定义了
std::string CStringToString(const CString& cstr)
{
	CT2CA pszConvertedAnsiString(cstr);
	std::string str(pszConvertedAnsiString);
	return str;
}


int CStringToInt(CString &a)
{
	std::string str = CStringToString(a);
	return atoi(str.c_str());
}

void CDatastructurepractice1mfcDlg::main_list_show()
{
	CString insert_index;
	int last_row;
	main_list.DeleteAllItems();
	for (size_t i = 0;i < seqlist_ptr->getInstance()->return_num();i++)
	{
		insert_index = _T("节点");
		insert_index += std::to_string(i + 1).c_str();
		//insert_index = std::to_string(i+1).c_str();//int转Cstring
		last_row = main_list.GetItemCount();
		last_row = main_list.InsertItem(last_row, insert_index);
		insert_index = std::to_string(seqlist_ptr->getInstance()->show(i)).c_str();
		main_list.SetItemText(last_row, 1, insert_index);
	}
	for (size_t i = seqlist_ptr->getInstance()->return_num(); i < seqlist_ptr->getInstance()->return_size(); i++)
	{
		insert_index = _T("节点");
		insert_index += std::to_string(i + 1).c_str();
		//insert_index = std::to_string(i + 1).c_str();//int转Cstring
		last_row = main_list.GetItemCount();
		last_row = main_list.InsertItem(last_row, insert_index);
	
	}

}

void CDatastructurepractice1mfcDlg::main_list_show_mylist()
{
	//删除所有列
	for (size_t i = 0; i < main_list_mylist.GetHeaderCtrl()->GetItemCount();)
	{
		main_list_mylist.DeleteColumn(i);
	}
	main_list_mylist.DeleteAllItems();

	CString insert_index;
	main_list_mylist.InsertColumn(0, _T(""), LVCFMT_LEFT, 100);
	int count = 0;
	int num = MyList_ptr->getInstance()->return_num();
	//打印空表
	{
		insert_index = std::to_string(0).c_str();
		insert_index += _T("号节点数据（空表）");

		main_list_mylist.InsertColumn(count + 1, insert_index, LVCFMT_LEFT, 230);
		insert_index = std::to_string(0).c_str();
		insert_index += _T("号节点Link");
		main_list_mylist.InsertColumn(count + 2, insert_index, LVCFMT_LEFT, 230);
		main_list_mylist.InsertColumn(count + 3, _T(""), LVCFMT_LEFT, 100);
		count += 3;
	}
	//打印列
	for (size_t i = 1; i < num; i++)
	{
		insert_index = std::to_string(i).c_str();
		insert_index += _T("号节点数据");

		main_list_mylist.InsertColumn(count +1, insert_index, LVCFMT_LEFT, 230);
		insert_index = std::to_string(i).c_str();
		insert_index += _T("号节点Link");
		main_list_mylist.InsertColumn(count + 2, insert_index, LVCFMT_LEFT, 230);
		main_list_mylist.InsertColumn(count + 3, _T(""), LVCFMT_LEFT, 100);
		count += 3;

	}
	main_list_mylist.InsertColumn(count + 1, _T(""), LVCFMT_LEFT, 150);
	count = 0;
	main_list_mylist.InsertItem(0, _T("单链表"));
	main_list_mylist.InsertItem(1, _T("节点地址"));
	//打印链表
	for (size_t i = 0; i < num; i++)
	{
		//insert_index = std::to_string(i).c_str();
		//insert_index = std::to_string(MyList_ptr->getInstance()->get_node_ptr(i)->data).c_str();
		//把下面这里替换了，如果有bug换回来
		//MyList_ptr->getInstance()->get_node_ptr(i)->data  ->  MyList_ptr->getInstance()->show(i)
		insert_index = std::to_string(MyList_ptr->getInstance()->show(i)).c_str();
		main_list_mylist.SetItemText(0, count + 1, insert_index);
		insert_index = _T("Ox");
		//打印节点link地址
		insert_index += ptr_to_HexNumber(MyList_ptr->getInstance()->get_node_ptr(i)->link).c_str();//将ptr转为(uintptr_t)类型才能打印
		main_list_mylist.SetItemText(0, count + 2, insert_index);
		main_list_mylist.SetItemText(0, count + 3, _T("----->"));
		count += 3;
	}
	main_list_mylist.SetItemText(0, count + 1, _T("NULL"));

	count = 0;
	//打印节点地址
	for (size_t i = 0; i < num; i++)
	{
		//insert_index = std::to_string(i).c_str();
		insert_index = _T("Ox");
		insert_index += ptr_to_HexNumber(MyList_ptr->getInstance()->get_node_ptr(i)).c_str();//将ptr转为(uintptr_t)类型才能打印

		
		main_list_mylist.SetItemText(1, count + 1, insert_index);
		main_list_mylist.SetItemText(1, count + 2, _T(""));
		main_list_mylist.SetItemText(1, count + 3, _T(""));
		count += 3;
	}
	count = 0;
	//打印first和end地址；
	main_list_mylist.InsertItem(2, _T(""));
	main_list_mylist.InsertItem(3, _T("监控台"));
	main_list_mylist.InsertItem(4, _T("first地址"));
	main_list_mylist.InsertItem(5, _T("end地址"));
	main_list_mylist.InsertItem(6, _T("list地址"));
	insert_index = _T("Ox");
	insert_index += ptr_to_HexNumber(MyList_ptr->getInstance()->return_first()).c_str();//将ptr转为(uintptr_t)类型再转16进制打印
	main_list_mylist.SetItemText(4, 1, insert_index);
	insert_index = _T("Ox");
	insert_index += ptr_to_HexNumber(MyList_ptr->getInstance()->return_end()).c_str();//将ptr转为(uintptr_t)类型再转16进制打印
	main_list_mylist.SetItemText(5, 1, insert_index);
	insert_index = _T("Ox");
	insert_index += ptr_to_HexNumber(MyList_ptr->getInstance()->return_list()).c_str();//将ptr转为(uintptr_t)类型再转16进制打印
	main_list_mylist.SetItemText(6, 1, insert_index);

	/*
	
	CString insert_index;
	int last_row;
	main_list.DeleteAllItems();
	for (size_t i = 0;
		i < seqlist_ptr->getInstance()->return_num();
		i++)
	{
		insert_index = std::to_string(i + 1).c_str();//int转Cstring
		last_row = main_list.GetItemCount();
		last_row = main_list.InsertItem(last_row, insert_index);
		insert_index = std::to_string(seqlist_ptr->getInstance()->show(i)).c_str();
		main_list.SetItemText(last_row, 1, insert_index);
	}
	for (size_t i = seqlist_ptr->getInstance()->return_num(); i < seqlist_ptr->getInstance()->return_size(); i++)
	{
		insert_index = std::to_string(i + 1).c_str();//int转Cstring
		last_row = main_list.GetItemCount();
		last_row = main_list.InsertItem(last_row, insert_index);

	}*/
	
}

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CDatastructurepractice1mfcDlg 对话框



CDatastructurepractice1mfcDlg::CDatastructurepractice1mfcDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DATA_STRUCTURE_PRACTICE1_MFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDatastructurepractice1mfcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_MAIN_EDIT, main_edit);
	DDX_Control(pDX, IDC_MAIN_LIST, main_list);
	DDX_Control(pDX, IDC_MAIN_LIST_MYLIST, main_list_mylist);
}

BEGIN_MESSAGE_MAP(CDatastructurepractice1mfcDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD_BUTTON, &CDatastructurepractice1mfcDlg::OnBnClickedAddButton)
	ON_BN_CLICKED(IDC_DEL_N_BUTTON, &CDatastructurepractice1mfcDlg::OnBnClickedDelButton)
	//ON_EN_CHANGE(IDC_MAIN_EDIT, &CDatastructurepractice1mfcDlg::OnEnChangeMainEdit)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_MAIN_LIST, &CDatastructurepractice1mfcDlg::OnLvnItemchangedMainList)
	ON_BN_CLICKED(IDC_INI_BUTTON, &CDatastructurepractice1mfcDlg::OnBnClickedIniButton)
	ON_WM_SIZE()//自适应大小
	ON_BN_CLICKED(IDC_INSERT_BUTTON, &CDatastructurepractice1mfcDlg::OnBnClickedInsertButton)
	ON_BN_CLICKED(IDC_DEL_N_EDIT, &CDatastructurepractice1mfcDlg::OnBnClickedDelNEdit)
	ON_BN_CLICKED(IDC_DEL_NUMBER_BUTTON, &CDatastructurepractice1mfcDlg::OnBnClickedDelNumberButton)
	ON_BN_CLICKED(IDOK, &CDatastructurepractice1mfcDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDatastructurepractice1mfcDlg::OnBnClickedCancel)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_MAIN_LIST_MYLIST, &CDatastructurepractice1mfcDlg::OnLvnItemchangedMainListMylist)
	ON_BN_CLICKED(IDC_INI_BUTTON_MYLIST, &CDatastructurepractice1mfcDlg::OnBnClickedIniButtonMylist)
	ON_BN_CLICKED(IDC_ADD_MYLIST_BUTTON, &CDatastructurepractice1mfcDlg::OnBnClickedAddMylistButton)
	ON_BN_CLICKED(IDC_INSERT_MYLIST_BUTTON, &CDatastructurepractice1mfcDlg::OnBnClickedInsertMylistButton)
	ON_BN_CLICKED(IDC_DEL_N_MYLIST_BUTTON, &CDatastructurepractice1mfcDlg::OnBnClickedDelNMylistButton)
	ON_BN_CLICKED(IDC_DEL_NUMBER_MYLIST_BUTTON, &CDatastructurepractice1mfcDlg::OnBnClickedDelNumberMylistButton)
	ON_BN_CLICKED(IDC_INSERT_ACCORD_NUMBER_BUTTON, &CDatastructurepractice1mfcDlg::OnBnClickedInsertAccordNumberButton)
	ON_BN_CLICKED(IDC_INSERT_ACCORD_NUMBER_SEQ_BUTTON, &CDatastructurepractice1mfcDlg::OnBnClickedInsertAccordNumberSeqButton)
	ON_BN_CLICKED(IDC_INVERSE_MYLIST_BUTTON, &CDatastructurepractice1mfcDlg::OnBnClickedInverseMylistButton)
	//ON_BN_CLICKED(ID_32771, &CDatastructurepractice1mfcDlg::OnBnClickedInverseMylistButton)//帮助按钮
	ON_WM_EXITSIZEMOVE()
	ON_WM_SIZING()
	ON_COMMAND(ID_32772, &CDatastructurepractice1mfcDlg::On32772_HELP)
	ON_COMMAND(ID_32773, &CDatastructurepractice1mfcDlg::On32773_about)
	ON_COMMAND(ID_32776, &CDatastructurepractice1mfcDlg::On32776)
	ON_COMMAND(ID_32777, &CDatastructurepractice1mfcDlg::On32777)
END_MESSAGE_MAP()


// CDatastructurepractice1mfcDlg 消息处理程序

BOOL CDatastructurepractice1mfcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	//ShowWindow(SW_MAXIMIZE);

	//ShowWindow(SW_MINIMIZE);

	// TODO: 在此添加额外的初始化代码
	//main_list.SetExtendedStyle(LVS_EX_CHECKBOXES); //设置列表控件使用复选框
	main_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	main_list.InsertColumn(0, _T("顺序表"), LVCFMT_LEFT, 100);
	main_list.InsertColumn(1, _T("数据"), LVCFMT_LEFT, 100);
	main_list_mylist.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES );
	main_list_mylist.InsertColumn(0, _T("单链表"), LVCFMT_LEFT, 100);
	/*	main_list_mylist.InsertColumn(1, _T("节点1"), LVCFMT_LEFT, 100);
	main_list_mylist.InsertColumn(2, _T("Link"), LVCFMT_LEFT, 100);*/
	//初始化菜单
	m_Menu.LoadMenu(IDR_MAIN_MENU);
	SetMenu(&m_Menu);

	//自适应大小操作
	//ShowWindow(SW_SHOWMAXIMIZED); // 进入界面就将界面最大化
	GetClientRect(&m_rect); // 获取客户界面的尺寸


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CDatastructurepractice1mfcDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CDatastructurepractice1mfcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CDatastructurepractice1mfcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//自适应大小
void CDatastructurepractice1mfcDlg::ChangeSize(UINT nID, double x, double y) // nID为控件ID，x,y分别为对话框的当前长和宽
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

void CDatastructurepractice1mfcDlg::ChangeSize(UINT nID, double x, double y, CRect& t_rect)
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

void CDatastructurepractice1mfcDlg::OnSize(UINT nType, int cx, int cy)
{

	//自适应大小
	//Sleep(180);
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

void CDatastructurepractice1mfcDlg::OnLbnSelchangeList1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CDatastructurepractice1mfcDlg::OnBnClickedAddButton()
{
	// TODO: 在此添加控件通知处理程序代码
	add_dlg dlg;
	dlg.DoModal();
	bool detect_out_range_index;
	if (dlg.index)
	{
		detect_out_range_index=seqlist_ptr->getInstance()->add(CStringToInt(dlg.add_cstr_inf));
	}
	else
	{
		return;
	}
	if (!detect_out_range_index)
	{
		error_dlg err_dlg;
		err_dlg.DoModal();
		return;
	}

	//展示函数
	UpdateData(TRUE);
	main_list_show();
	// 获取要添加的文本
	
}


void CDatastructurepractice1mfcDlg::OnBnClickedDelButton()
{
	

}


void CDatastructurepractice1mfcDlg::OnEnChangeMainEdit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CDatastructurepractice1mfcDlg::OnLvnItemchangedMainList(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	/*if (pNMLV->uChanged & LVIF_STATE)
	{
		// 判断当前列表项的复选框是否被选中
		BOOL bChecked = main_list.GetCheck(pNMLV->iItem);

		// 如果当前列表项的复选框被选中，则取消其他列表项的选择状态
		if (bChecked)
		{
			for (int i = 0; i < main_list.GetItemCount(); i++)
			{
				if (i != pNMLV->iItem)
				{
					main_list.SetCheck(i, FALSE);
				}
			}
		}
	}*/
	*pResult = 0;
}


void CDatastructurepractice1mfcDlg::OnBnClickedIniButton()
{
	// TODO: 在此添加控件通知处理程序代码
	ini_dialog dlg;
	dlg.DoModal();
	//下面这一行是将CString转为string再转为int的操作
	bool detect_out_range_index;
	if (dlg.index)
	{
		if (seqlist_ptr)
		{
			seqlist_ptr->~SeqList();

		}
		detect_out_range_index=seqlist_ptr->setInstance(CStringToInt(dlg.ini_n_edit), CStringToInt(dlg.ini_size_edit));
	}
	else
	{
		/*UpdateData(TRUE);
		main_list_show();*/

		return;
	}
	if (!detect_out_range_index)
	{
		error_dlg err_dlg;
		err_dlg.DoModal();
		return;
	}
	UpdateData(TRUE);
	// 将文本添加到ListBox
	main_list_show();
	

}


void CAboutDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码

}





void CDatastructurepractice1mfcDlg::OnBnClickedInsertButton()
{
	// TODO: 在此添加控件通知处理程序代码
	insert_dlg dlg;
	dlg.DoModal();
	bool detect_out_range_index;
	if (dlg.index)
	{
		detect_out_range_index=seqlist_ptr->getInstance()->insert(CStringToInt(dlg.insert_num), CStringToInt(dlg.insert_cstr_inf));
	}
	else
	{
		return;
	}
	if (!detect_out_range_index)
	{
		error_dlg err_dlg;
		err_dlg.DoModal();
		return;
	}
	//展示函数
	main_list_show();

	// 清空编辑框
	UpdateData(TRUE);

}


void CDatastructurepractice1mfcDlg::OnBnClickedDelNEdit()
{
	// TODO: 在此添加控件通知处理程序代码
	del_dlg dlg;
	dlg.DoModal();
	bool detect_out_range_index;
	if (dlg.index)
	{
		detect_out_range_index = seqlist_ptr->getInstance()->del(CStringToInt(dlg.del_num), 1);

	}
	else
	{
		return;
	}
	if (!detect_out_range_index)
	{
		error_dlg err_dlg;
		err_dlg.DoModal();
		return;
	}


	UpdateData(TRUE);
	main_list_show();
}


void CDatastructurepractice1mfcDlg::OnBnClickedDelNumberButton()
{
	// TODO: 在此添加控件通知处理程序代码
	del_num_dlg dlg;
	dlg.DoModal();
	bool detect_out_range_index;
	if (dlg.index)
	{
		detect_out_range_index=seqlist_ptr->getInstance()->del(CStringToInt(dlg.del_num));

	}
	else
	{
		return;
	}
	if (!detect_out_range_index)
	{
		error_dlg err_dlg;
		err_dlg.DoModal();
		return;
	}
	


	UpdateData(TRUE);
	main_list_show();

}


void CDatastructurepractice1mfcDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CDatastructurepractice1mfcDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CDatastructurepractice1mfcDlg::OnLvnItemchangedMainListMylist(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CDatastructurepractice1mfcDlg::OnBnClickedIniButtonMylist()
{
	// TODO: 在此添加控件通知处理程序代码
	ini_mylist_dlg dlg;
	dlg.DoModal();
	bool detect_out_range_index;
	//下面这一行是将CString转为string再转为int的操作
	if (dlg.index)
	{
		if (MyList_ptr)
		{
			MyList_ptr->~MyList();

		}
		
		MyList_ptr->setInstance(CStringToInt(dlg.ini_n_edit));
	}
	else
	{
		/*UpdateData(TRUE);
		main_list_show();*/

		return;
	}
	UpdateData(TRUE);
	// 将文本添加到ListBox
	main_list_show_mylist();
	
}


void CDatastructurepractice1mfcDlg::OnBnClickedAddMylistButton()
{
	// TODO: 在此添加控件通知处理程序代码
	add_dlg dlg;
	dlg.DoModal();
	bool detect_out_range_index;
	if (dlg.index)
	{
		detect_out_range_index = MyList_ptr->getInstance()->add(CStringToInt(dlg.add_cstr_inf));
	}
	else
	{
		return;
	}
	if (!detect_out_range_index)
	{
		error_dlg err_dlg;
		err_dlg.DoModal();
		return;
	}

	//展示函数
	UpdateData(TRUE);
	main_list_show_mylist();
}


void CDatastructurepractice1mfcDlg::OnBnClickedInsertMylistButton()
{
	// TODO: 在此添加控件通知处理程序代码
	insert_dlg dlg;
	dlg.DoModal();
	bool detect_out_range_index;
	if (dlg.index)
	{
		detect_out_range_index = MyList_ptr->getInstance()->insert(CStringToInt(dlg.insert_num), CStringToInt(dlg.insert_cstr_inf));
	}
	else
	{
		return;
	}
	if (!detect_out_range_index)
	{
		error_dlg err_dlg;
		err_dlg.DoModal();
		return;
	}
	//展示函数
	main_list_show_mylist();

	// 清空编辑框
	UpdateData(TRUE);
}


void CDatastructurepractice1mfcDlg::OnBnClickedDelNMylistButton()
{
	// TODO: 在此添加控件通知处理程序代码
	del_dlg dlg;
	dlg.DoModal();
	bool detect_out_range_index;
	if (dlg.index)
	{
		detect_out_range_index = MyList_ptr->getInstance()->del(CStringToInt(dlg.del_num), 1);

	}
	else
	{
		return;
	}
	if (!detect_out_range_index)
	{
		error_dlg err_dlg;
		err_dlg.DoModal();
		return;
	}


	UpdateData(TRUE);
	main_list_show_mylist();
}


void CDatastructurepractice1mfcDlg::OnBnClickedDelNumberMylistButton()
{
	// TODO: 在此添加控件通知处理程序代码
	del_num_dlg dlg;
	dlg.DoModal();
	bool detect_out_range_index;
	if (dlg.index)
	{
		detect_out_range_index = MyList_ptr->getInstance()->del(CStringToInt(dlg.del_num));

	}
	else
	{
		return;
	}
	if (!detect_out_range_index)
	{
		error_dlg err_dlg;
		err_dlg.DoModal();
		return;
	}



	UpdateData(TRUE);
	main_list_show_mylist();
}


void CDatastructurepractice1mfcDlg::OnBnClickedInsertAccordNumberButton()
{
	// TODO: 在此添加控件通知处理程序代码
	insert_accord_number_dlg dlg;
	dlg.DoModal();
	bool detect_out_range_index;
	if (dlg.index)
	{
		detect_out_range_index = MyList_ptr->getInstance()->insert(CStringToInt(dlg.insert_n), CStringToInt(dlg.insert_number),1);
	}
	else
	{
		return;
	}
	if (!detect_out_range_index)
	{
		error_dlg err_dlg;
		err_dlg.DoModal();
		return;
	}
	//展示函数
	main_list_show_mylist();

	// 清空编辑框
	UpdateData(TRUE);
}


void CDatastructurepractice1mfcDlg::OnBnClickedInsertAccordNumberSeqButton()
{
	// TODO: 在此添加控件通知处理程序代码
	insert_accord_number_dlg dlg;
	dlg.DoModal();
	bool detect_out_range_index;
	if (dlg.index)
	{
		detect_out_range_index = seqlist_ptr->getInstance()->insert(CStringToInt(dlg.insert_n), CStringToInt(dlg.insert_number), 1);
	}
	else
	{
		return;
	}
	if (!detect_out_range_index)
	{
		error_dlg err_dlg;
		err_dlg.DoModal();
		return;
	}
	//展示函数
	main_list_show();

	// 清空编辑框
	UpdateData(TRUE);
}


void CDatastructurepractice1mfcDlg::OnBnClickedInverseMylistButton()
{
	// TODO: 在此添加控件通知处理程序代码
	MyList_ptr->getInstance()->inverse();
	main_list_show_mylist();

	// 清空编辑框
	UpdateData(TRUE);
}


void CDatastructurepractice1mfcDlg::OnExitSizeMove()
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


void CDatastructurepractice1mfcDlg::OnSizing(UINT fwSide, LPRECT pRect)
{
	CDialogEx::OnSizing(fwSide, pRect);
	// TODO: 在此处添加消息处理程序代码

}


void CDatastructurepractice1mfcDlg::On32772_HELP()
{
	// TODO: 在此添加命令处理程序代码
	help_dlg dlg;
	dlg.DoModal();
}




void CDatastructurepractice1mfcDlg::On32773_about()
{
	// TODO: 在此添加命令处理程序代码
	my_about_dlg dlg;
	dlg.DoModal();
}


void CDatastructurepractice1mfcDlg::On32776()
{
	// TODO: 在此添加命令处理程序代码
	my_parenthesis_match_dlg dlg;
	dlg.DoModal();
}


void CDatastructurepractice1mfcDlg::On32777()
{
	// TODO: 在此添加命令处理程序代码
	my_painting_dlg dlg;
	dlg.DoModal();
}
