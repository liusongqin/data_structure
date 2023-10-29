#pragma once
#include "afxdialogex.h"


// my_about_dlg 对话框

class my_about_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(my_about_dlg)

public:
	my_about_dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~my_about_dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_ABOUT_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
