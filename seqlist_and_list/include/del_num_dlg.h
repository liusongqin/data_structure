#pragma once
#include "afxdialogex.h"


// del_num_dlg 对话框

class del_num_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(del_num_dlg)

public:
	del_num_dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~del_num_dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DEL_NUM_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString del_num=0;
	int index = 0;
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeDelNumEdit();
	virtual BOOL OnInitDialog();
};
