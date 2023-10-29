// help_dlg.cpp: 实现文件
//

#include "pch.h"
#include "Data_structure_practice1_mfc.h"
#include "afxdialogex.h"
#include "help_dlg.h"


// help_dlg 对话框

IMPLEMENT_DYNAMIC(help_dlg, CDialogEx)

help_dlg::help_dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_HELP_DIALOG, pParent)
	, web_edit("https://github.com/liusongqin/data_structure")
	,qq_edit("2336854948@qq.com")
{

}

help_dlg::~help_dlg()
{
}

void help_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_WEB_EDIT, web_edit);
	DDX_Text(pDX, IDC_QQ_EDIT, qq_edit);

}


BEGIN_MESSAGE_MAP(help_dlg, CDialogEx)
	ON_EN_CHANGE(IDC_WEB_EDIT, &help_dlg::OnEnChangeWebEdit)
	ON_EN_CHANGE(IDC_QQ_EDIT, &help_dlg::OnEnChangeQqEdit)
END_MESSAGE_MAP()


// help_dlg 消息处理程序


void help_dlg::OnEnChangeWebEdit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void help_dlg::OnEnChangeQqEdit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


BOOL help_dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
