#pragma once
#include "afxdialogex.h"


// ini_mylist_dlg 对话框

class ini_mylist_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(ini_mylist_dlg)

public:
	ini_mylist_dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ini_mylist_dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INI_MYLIST_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeIniMylistEdit();
	//int ini_n_edit=0;
	CString ini_n_edit=0;

	bool index = 0;	

	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
