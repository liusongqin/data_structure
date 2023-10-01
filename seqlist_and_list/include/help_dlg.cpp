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
{

}

help_dlg::~help_dlg()
{
}

void help_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(help_dlg, CDialogEx)
END_MESSAGE_MAP()


// help_dlg 消息处理程序
