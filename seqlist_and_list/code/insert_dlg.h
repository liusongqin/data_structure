#pragma once
#include "afxdialogex.h"


// insert_dlg 对话框

class insert_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(insert_dlg)

public:
	insert_dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~insert_dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INSERT_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CString insert_num=0;
	CString insert_cstr_inf=0;
	bool index=0;//用来看用户按没按OK键
	afx_msg void OnEnChangeInsertNumEdit();
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
