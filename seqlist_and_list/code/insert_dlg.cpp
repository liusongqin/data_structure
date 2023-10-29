// insert_dlg.cpp: 实现文件
//

#include "pch.h"
#include "Data_structure_practice1_mfc.h"
#include "afxdialogex.h"
#include "insert_dlg.h"


// insert_dlg 对话框

IMPLEMENT_DYNAMIC(insert_dlg, CDialogEx)

insert_dlg::insert_dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INSERT_DIALOG, pParent)

{

}

insert_dlg::~insert_dlg()
{
}

void insert_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_INSERT_EDIT, insert_cstr_inf);
	DDX_Text(pDX, IDC_INSERT_NUM_EDIT, insert_num);


}


BEGIN_MESSAGE_MAP(insert_dlg, CDialogEx)
	ON_EN_CHANGE(IDC_INSERT_EDIT, &insert_dlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_INSERT_NUM_EDIT, &insert_dlg::OnEnChangeInsertNumEdit)
	ON_BN_CLICKED(IDOK, &insert_dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// insert_dlg 消息处理程序


void insert_dlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void insert_dlg::OnEnChangeInsertNumEdit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void insert_dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItemText(IDC_INSERT_EDIT, insert_cstr_inf);
	GetDlgItemText(IDC_INSERT_NUM_EDIT, insert_num);
	index = 1;
	CDialogEx::OnOK();
}


BOOL insert_dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	GetDlgItem(IDC_INSERT_NUM_EDIT)->SetFocus();

	// 返回FALSE以防止对话框自动设置焦点
	return FALSE;
	// 异常: OCX 属性页应返回 FALSE
}
