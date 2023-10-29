// insert_accord_number_dlg.cpp: 实现文件
//

#include "pch.h"
#include "Data_structure_practice1_mfc.h"
#include "afxdialogex.h"
#include "insert_accord_number_dlg.h"


// insert_accord_number_dlg 对话框

IMPLEMENT_DYNAMIC(insert_accord_number_dlg, CDialogEx)

insert_accord_number_dlg::insert_accord_number_dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INSERT_ACCORD_NUMBER_DIALOG, pParent)
{

}

insert_accord_number_dlg::~insert_accord_number_dlg()
{
}

void insert_accord_number_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(insert_accord_number_dlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &insert_accord_number_dlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_INSERT_ACCORD_NUMBER_EDIT, &insert_accord_number_dlg::OnEnChangeInsertAccordNumberEdit)
	ON_EN_CHANGE(IDC_INSERT_NUMBER_ACC_EDIT, &insert_accord_number_dlg::OnEnChangeInsertNumberAccEdit)
END_MESSAGE_MAP()


// insert_accord_number_dlg 消息处理程序


void insert_accord_number_dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItemText(IDC_INSERT_ACCORD_NUMBER_EDIT, insert_n);
	GetDlgItemText(IDC_INSERT_NUMBER_ACC_EDIT, insert_number);
	index = 1;
	CDialogEx::OnOK();
}


BOOL insert_accord_number_dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	GetDlgItem(IDC_INSERT_ACCORD_NUMBER_EDIT)->SetFocus();

	// 返回FALSE以防止对话框自动设置焦点
	return FALSE;
	//return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void insert_accord_number_dlg::OnEnChangeInsertAccordNumberEdit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void insert_accord_number_dlg::OnEnChangeInsertNumberAccEdit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
