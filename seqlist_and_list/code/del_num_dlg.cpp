// del_num_dlg.cpp: 实现文件
//

#include "pch.h"
#include "Data_structure_practice1_mfc.h"
#include "afxdialogex.h"
#include "del_num_dlg.h"


// del_num_dlg 对话框

IMPLEMENT_DYNAMIC(del_num_dlg, CDialogEx)

del_num_dlg::del_num_dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DEL_NUM_DIALOG, pParent)
{

}

del_num_dlg::~del_num_dlg()
{
}

void del_num_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_DEL_NUM_EDIT, del_num);
}


BEGIN_MESSAGE_MAP(del_num_dlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &del_num_dlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_DEL_NUM_EDIT, &del_num_dlg::OnEnChangeDelNumEdit)
END_MESSAGE_MAP()


// del_num_dlg 消息处理程序


void del_num_dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItemText(IDC_DEL_NUM_EDIT, del_num);
	index = 1;
	CDialogEx::OnOK();
}


void del_num_dlg::OnEnChangeDelNumEdit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


BOOL del_num_dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	GetDlgItem(IDC_DEL_NUM_EDIT)->SetFocus();

	return false;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
