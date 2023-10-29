// del_dlg.cpp: 实现文件
//

#include "pch.h"
#include "Data_structure_practice1_mfc.h"
#include "afxdialogex.h"
#include "del_dlg.h"


// del_dlg 对话框

IMPLEMENT_DYNAMIC(del_dlg, CDialogEx)

del_dlg::del_dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DEL_DIALOG, pParent)
{

}

del_dlg::~del_dlg()
{
}

void del_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_DEL_EDIT, del_num);
}


BEGIN_MESSAGE_MAP(del_dlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &del_dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// del_dlg 消息处理程序


void del_dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItemText(IDC_DEL_EDIT, del_num);
	index = 1;
	CDialogEx::OnOK();
}


BOOL del_dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	GetDlgItem(IDC_DEL_EDIT)->SetFocus();

	return false;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
