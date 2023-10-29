// add_dlg.cpp: 实现文件
//

#include "pch.h"
#include "Data_structure_practice1_mfc.h"
#include "afxdialogex.h"
#include "add_dlg.h"


// add_dlg 对话框

IMPLEMENT_DYNAMIC(add_dlg, CDialogEx)

add_dlg::add_dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADD_DIALOG, pParent)
{

}

add_dlg::~add_dlg()
{
}

void add_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_CST_INF_EDIT, add_cstr_inf);
}


BEGIN_MESSAGE_MAP(add_dlg, CDialogEx)
	ON_EN_CHANGE(IDC_CST_INF_EDIT, &add_dlg::OnEnChangeCstInfEdit)
	ON_BN_CLICKED(IDOK, &add_dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// add_dlg 消息处理程序


void add_dlg::OnEnChangeCstInfEdit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void add_dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItemText(IDC_CST_INF_EDIT, add_cstr_inf);
	index = 1;
	CDialogEx::OnOK();
}


BOOL add_dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	GetDlgItem(IDC_CST_INF_EDIT)->SetFocus();
	return false;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
