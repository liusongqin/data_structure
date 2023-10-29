#pragma once
#include "afxdialogex.h"
#include <string>
#include <sstream>
#include"MyList.h"

// my_parenthesis_match_dlg 对话框

class my_parenthesis_match_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(my_parenthesis_match_dlg)

public:
	my_parenthesis_match_dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~my_parenthesis_match_dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_PAR_MATCH_DLG };
#endif

protected:
	HICON m_hIcon;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	//自适应大小
	BOOL change_flag;
	CRect m_rect;
	bool change_index = false;//自适应大小用,为了达到最大化之后才能调用一次onsize函数
	void ChangeSize(UINT nID, double x, double y);
	void ChangeSize(UINT nID, double x, double y, CRect& t_rect);
	//
	bool index = 0;//用来看用户按没按OK键
	virtual BOOL OnInitDialog();
	afx_msg void OnExitSizeMove();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnEnChangeParMatchEdit();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnPaint();
	CString par_match_edit;
	afx_msg void OnBnClickedOk();
	bool parenthesis_match_fun(const char* e);
	afx_msg void OnBnClickedMatchButton();
	void list_show();
	afx_msg void OnLvnItemchangedParMatchList(NMHDR* pNMHDR, LRESULT* pResult);
	CListCtrl match_list;
	int last_row=0;//打印list用的，最后一行
	afx_msg void OnBnClickedInfixToButton();
	CFont m_font;//字体大小设置
	afx_msg void OnBnClickedInfixToReButton();
};
