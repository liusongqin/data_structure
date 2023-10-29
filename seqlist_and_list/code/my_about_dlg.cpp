// my_about_dlg.cpp: 实现文件
//

#include "pch.h"
#include "Data_structure_practice1_mfc.h"
#include "afxdialogex.h"
#include "my_about_dlg.h"


// my_about_dlg 对话框

IMPLEMENT_DYNAMIC(my_about_dlg, CDialogEx)

my_about_dlg::my_about_dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY_ABOUT_DIALOG, pParent)
{

}

my_about_dlg::~my_about_dlg()
{
}

void my_about_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(my_about_dlg, CDialogEx)
END_MESSAGE_MAP()


// my_about_dlg 消息处理程序
