
// Data_structure_practice1_mfcDlg.h: 头文件
//

#pragma once
#include"SeqList.h"
#include"MyList.h"

// CDatastructurepractice1mfcDlg 对话框
class CDatastructurepractice1mfcDlg : public CDialogEx
{
// 构造
public:
	CDatastructurepractice1mfcDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DATA_STRUCTURE_PRACTICE1_MFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	//自适应大小操作
	BOOL change_flag;
	CRect m_rect;
	bool change_index=false;//自适应大小用,为了达到最大化之后才能调用一次onsize函数
	void ChangeSize(UINT nID, double x, double y);
	void ChangeSize(UINT nID, double x, double y, CRect& t_rect);
	//第二次自适应尝试
	//CList<CRect, CRect&> m_listRect;
	//void GetControlRects();
	//
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedAddButton();
	afx_msg void OnBnClickedDelButton();
	afx_msg void OnEnChangeMainEdit();
	CEdit main_edit;
	CListBox show_list_box;
	afx_msg void OnLvnItemchangedMainList(NMHDR* pNMHDR, LRESULT* pResult);
	CListCtrl main_list;
	afx_msg void OnBnClickedIniButton();
	SeqList* seqlist_ptr;
	MyList* MyList_ptr;

	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBnClickedInsertButton();
	void main_list_show();
	void main_list_show_mylist();
	afx_msg void OnBnClickedDelNEdit();
	afx_msg void OnBnClickedDelNumberButton();
	bool choose_index;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnLvnItemchangedMainListMylist(NMHDR* pNMHDR, LRESULT* pResult);
	CListCtrl main_list_mylist;
	afx_msg void OnBnClickedIniButtonMylist();
	afx_msg void OnBnClickedAddMylistButton();
	afx_msg void OnBnClickedInsertMylistButton();
	afx_msg void OnBnClickedDelNMylistButton();
	afx_msg void OnBnClickedDelNumberMylistButton();
	afx_msg void OnBnClickedInsertAccordNumberButton();
	afx_msg void OnBnClickedInsertAccordNumberSeqButton();
	afx_msg void OnBnClickedInverseMylistButton();
	afx_msg void OnExitSizeMove();
	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
	CMenu m_Menu;
	afx_msg void On32772_HELP();
	afx_msg void On32773_about();
};
