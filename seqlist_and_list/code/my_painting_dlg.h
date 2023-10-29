#pragma once
#include "afxdialogex.h"


// my_painting_dlg 对话框

class my_painting_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(my_painting_dlg)

public:
	my_painting_dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~my_painting_dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_PAINTING_DIALOG };
#endif

protected:
	HICON m_hIcon;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	bool m_bMouseDown;
public:
	//自适应大小
	BOOL change_flag;
	CRect m_rect;
	bool change_index = false;//自适应大小用,为了达到最大化之后才能调用一次onsize函数
	void ChangeSize(UINT nID, double x, double y);
	void ChangeSize(UINT nID, double x, double y, CRect& t_rect);

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	CPoint m_ptPrev;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	virtual BOOL OnInitDialog();
	afx_msg void OnExitSizeMove();
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
