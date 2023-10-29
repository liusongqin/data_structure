// error_dlg.cpp: 实现文件
//

#include "pch.h"
#include "Data_structure_practice1_mfc.h"
#include "afxdialogex.h"
#include "error_dlg.h"


// error_dlg 对话框

IMPLEMENT_DYNAMIC(error_dlg, CDialogEx)

error_dlg::error_dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ERROR_DIALOG, pParent)
{

}

error_dlg::~error_dlg()
{
}

void error_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(error_dlg, CDialogEx)
END_MESSAGE_MAP()


// error_dlg 消息处理程序


BOOL error_dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_static.SubclassDlgItem(IDC_STATIC, this);
	m_font.CreatePointFont(170, _T("楷体"));
	m_static.SetFont(&m_font);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
