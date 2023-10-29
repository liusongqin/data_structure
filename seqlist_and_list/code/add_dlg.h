#pragma once
#include "afxdialogex.h"


// add_dlg 对话框

class add_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(add_dlg)

public:
	add_dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~add_dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	
public:
	afx_msg void OnEnChangeCstInfEdit();
	CString add_cstr_inf=0;
	bool index = 0;//用于判断点没点ok
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
