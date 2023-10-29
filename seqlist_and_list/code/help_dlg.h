#pragma once
#include "afxdialogex.h"


// help_dlg 对话框

class help_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(help_dlg)

public:
	help_dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~help_dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HELP_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeWebEdit();
	afx_msg void OnEnChangeQqEdit();
	CString web_edit;
	CString qq_edit;

	virtual BOOL OnInitDialog();
};
