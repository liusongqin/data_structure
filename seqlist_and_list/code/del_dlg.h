#pragma once
#include "afxdialogex.h"


// del_dlg 对话框

class del_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(del_dlg)

public:
	del_dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~del_dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DEL_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString del_num=0;
	bool index=0;

	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
