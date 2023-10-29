// ini_dialog.cpp: 实现文件
//

#include "pch.h"
#include "Data_structure_practice1_mfc.h"
#include "afxdialogex.h"
#include "ini_dialog.h"


// ini_dialog 对话框

IMPLEMENT_DYNAMIC(ini_dialog, CDialogEx)

ini_dialog::ini_dialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INI_DIALOG, pParent)
{

}

ini_dialog::~ini_dialog()
{
}

void ini_dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_INI_N_EDIT, ini_n_edit);
	DDX_Text(pDX, IDC_INI_SIZE_EDIT, ini_size_edit);
}


BEGIN_MESSAGE_MAP(ini_dialog, CDialogEx)
	ON_EN_CHANGE(IDC_INI_N_EDIT, &ini_dialog::OnEnChangeIniNEdit)
	ON_EN_CHANGE(IDC_INI_SIZE_EDIT, &ini_dialog::OnEnChangeIniSizeEdit)
	ON_BN_CLICKED(IDOK, &ini_dialog::OnBnClickedOk)
END_MESSAGE_MAP()


// ini_dialog 消息处理程序


void ini_dialog::OnEnChangeIniNEdit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void ini_dialog::OnEnChangeIniSizeEdit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void ini_dialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItemText(IDC_INI_N_EDIT, ini_n_edit);
	GetDlgItemText(IDC_INI_SIZE_EDIT, ini_size_edit);

	index = 1;
	CDialogEx::OnOK();
}


BOOL ini_dialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	GetDlgItem(IDC_INI_N_EDIT)->SetFocus();

	return false;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
