#pragma once
#include "afxdialogex.h"


// error_dlg 对话框

class error_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(error_dlg)

public:
	error_dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~error_dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ERROR_DIALOG };
#endif

private:
	CFont m_font;
	CStatic m_static;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
