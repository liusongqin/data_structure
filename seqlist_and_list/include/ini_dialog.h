#pragma once
#include "afxdialogex.h"


// ini_dialog 对话框

class ini_dialog : public CDialogEx
{
	DECLARE_DYNAMIC(ini_dialog)

public:
	ini_dialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ini_dialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INI_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeIniNEdit();
	afx_msg void OnEnChangeIniSizeEdit();
	afx_msg void OnBnClickedOk();
	//int ini_n_edit;
	//int ini_size_edit;
	CString ini_n_edit=0;
	CString ini_size_edit=0;
	bool index = 0;
	virtual BOOL OnInitDialog();
};
