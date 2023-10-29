// ini_mylist_dlg.cpp: 实现文件
//

#include "pch.h"
#include "Data_structure_practice1_mfc.h"
#include "afxdialogex.h"
#include "ini_mylist_dlg.h"


// ini_mylist_dlg 对话框

IMPLEMENT_DYNAMIC(ini_mylist_dlg, CDialogEx)

ini_mylist_dlg::ini_mylist_dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INI_MYLIST_DIALOG, pParent)
{

}

ini_mylist_dlg::~ini_mylist_dlg()
{
}

void ini_mylist_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Text(pDX, IDC_INI_MYLIST_EDIT, ini_n_edit);

}


BEGIN_MESSAGE_MAP(ini_mylist_dlg, CDialogEx)
	ON_EN_CHANGE(IDC_INI_MYLIST_EDIT, &ini_mylist_dlg::OnEnChangeIniMylistEdit)
	ON_BN_CLICKED(IDOK, &ini_mylist_dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// ini_mylist_dlg 消息处理程序


void ini_mylist_dlg::OnEnChangeIniMylistEdit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void ini_mylist_dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItemText(IDC_INI_MYLIST_EDIT, ini_n_edit);
	index = 1;
	CDialogEx::OnOK();
}

//使用户可以不用点击编辑框就能输入
BOOL ini_mylist_dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	GetDlgItem(IDC_INI_MYLIST_EDIT)->SetFocus();

	// 返回FALSE以防止对话框自动设置焦点
	return FALSE;
	//return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
