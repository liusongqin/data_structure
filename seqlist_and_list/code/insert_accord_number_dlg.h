#pragma once
#include "afxdialogex.h"


// insert_accord_number_dlg 对话框

class insert_accord_number_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(insert_accord_number_dlg)

public:
	insert_accord_number_dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~insert_accord_number_dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INSERT_ACCORD_NUMBER_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString insert_number=0;
	CString insert_n=0;
	bool index = 0;


	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeInsertAccordNumberEdit();
	afx_msg void OnEnChangeInsertNumberAccEdit();
};
