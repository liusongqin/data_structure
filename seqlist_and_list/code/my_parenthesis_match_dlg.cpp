// my_parenthesis_match_dlg.cpp: 实现文件
//

#include "pch.h"
#include "Data_structure_practice1_mfc.h"
#include "afxdialogex.h"
#include "my_parenthesis_match_dlg.h"



// my_parenthesis_match_dlg 对话框

IMPLEMENT_DYNAMIC(my_parenthesis_match_dlg, CDialogEx)

my_parenthesis_match_dlg::my_parenthesis_match_dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY_PAR_MATCH_DLG, pParent)
{

}

my_parenthesis_match_dlg::~my_parenthesis_match_dlg()
{
}

void my_parenthesis_match_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_PAR_MATCH_EDIT, par_match_edit);
	DDX_Text(pDX, IDC_PAR_MATCH_EDIT, par_match_edit);
	DDX_Control(pDX, IDC_PAR_MATCH_LIST, match_list);
}


BEGIN_MESSAGE_MAP(my_parenthesis_match_dlg, CDialogEx)
	ON_WM_EXITSIZEMOVE()
	ON_WM_SIZE()
	ON_EN_CHANGE(IDC_PAR_MATCH_EDIT, &my_parenthesis_match_dlg::OnEnChangeParMatchEdit)
	ON_WM_QUERYDRAGICON()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDOK, &my_parenthesis_match_dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_MATCH_BUTTON, &my_parenthesis_match_dlg::OnBnClickedMatchButton)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_PAR_MATCH_LIST, &my_parenthesis_match_dlg::OnLvnItemchangedParMatchList)
	ON_BN_CLICKED(IDC_INFIX_TO_BUTTON, &my_parenthesis_match_dlg::OnBnClickedInfixToButton)
	ON_BN_CLICKED(IDC_INFIX_TO_RE_BUTTON, &my_parenthesis_match_dlg::OnBnClickedInfixToReButton)
END_MESSAGE_MAP()


// my_parenthesis_match_dlg 消息处理程序


void my_parenthesis_match_dlg::ChangeSize(UINT nID, double x, double y)
{
	CWnd* pWnd;
	pWnd = GetDlgItem(nID);
	if (pWnd != NULL) // 判断是否为空，因为在窗口创建的时候也会调用OnSize函数，但是此时各个控件还没有创建，所以pWnd为空
	{
		CRect rec;
		pWnd->GetWindowRect(&rec); // 获取控件变化前的大小
		ScreenToClient(&rec); // 将控件大小转换为在对话框中的区域坐标
		/*index1 = rec.right; index2 = m_rect.Width();
		index1 = index1 * x / index2;
		rec.right = index1;*/
		rec.left = (double)rec.left * x / (double)m_rect.Width(); // 按照比例调整控件的新位置
		rec.top = (double)rec.top * y / (double)m_rect.Height();
		rec.bottom = (double)rec.bottom * y / (double)m_rect.Height();
		rec.right = (double)rec.right * x / (double)m_rect.Width();


		pWnd->MoveWindow(rec); // 伸缩控件
		
		
	}

}

void my_parenthesis_match_dlg::ChangeSize(UINT nID, double x, double y, CRect& t_rect)
{
	CWnd* pWnd;
	pWnd = GetDlgItem(nID);
	if (pWnd != NULL) // 判断是否为空，因为在窗口创建的时候也会调用OnSize函数，但是此时各个控件还没有创建，所以pWnd为空
	{
		CRect rec;
		pWnd->GetWindowRect(&rec); // 获取控件变化前的大小
		ScreenToClient(&rec); // 将控件大小转换为在对话框中的区域坐标
		/*index1 = rec.right; index2 = m_rect.Width();
		index1 = index1 * x / index2;
		rec.right = index1;*/
		rec.left = (double)rec.left * x / (double)t_rect.left; // 按照比例调整控件的新位置
		rec.top = (double)rec.top * y / (double)t_rect.top;
		rec.bottom = (double)rec.bottom * y / (double)t_rect.bottom;
		rec.right = (double)rec.right * x / (double)t_rect.right;


		pWnd->MoveWindow(rec); // 伸缩控件
		
        
	}
}

BOOL my_parenthesis_match_dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	// TODO:  在此添加额外的初始化
	
	match_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	match_list.InsertColumn(0, _T("展示"), LVCFMT_LEFT, 180);
	match_list.InsertColumn(1, _T("过程状态"), LVCFMT_LEFT, 250);
	match_list.InsertColumn(2, _T("扫描进度"), LVCFMT_LEFT, 200);
	m_font.CreatePointFont(120, _T("Null"));
	match_list.SetFont(&m_font);

	GetClientRect(&m_rect); // 获取客户界面的尺寸
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	GetDlgItem(IDC_PAR_MATCH_EDIT)->SetFocus();

	return false;  
	// 异常: OCX 属性页应返回 FALSE
}


void my_parenthesis_match_dlg::OnExitSizeMove()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDialogEx::OnExitSizeMove();
	//if (nType != SIZE_MINIMIZED) // 如果确定OnInitDialog已经调用完毕
	CRect rec;
	rec.left = (double)m_rect.Width(); // 按照比例调整控件的新位置
	rec.top = (double)m_rect.Height();
	rec.bottom = (double)m_rect.Height();
	rec.right = (double)m_rect.Width();
	GetClientRect(&m_rect);
	HWND hwndChild = ::GetWindow(m_hWnd, GW_CHILD);
	int nID = 0;
	while (hwndChild)
	{
		nID = ::GetDlgCtrlID(hwndChild); // 获取控件ID
		ChangeSize(nID, m_rect.Width(), m_rect.Height(), rec);
		hwndChild = ::GetWindow(hwndChild, GW_HWNDNEXT);


	}
}


void my_parenthesis_match_dlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
		//正常大小和最大化执行
	if (nType == SIZE_MAXIMIZED) // 如果确定OnInitDialog已经调用完毕
	{

		HWND hwndChild = ::GetWindow(m_hWnd, GW_CHILD);
		int nID = 0;
		while (hwndChild)
		{
			nID = ::GetDlgCtrlID(hwndChild); // 获取控件ID
			ChangeSize(nID, cx, cy);
			hwndChild = ::GetWindow(hwndChild, GW_HWNDNEXT);

		}
		GetClientRect(&m_rect);
		change_index = 1;
	}
	if ((nType == SIZE_RESTORED) && (change_index))
	{
		HWND hwndChild = ::GetWindow(m_hWnd, GW_CHILD);
		int nID = 0;
		while (hwndChild)
		{
			nID = ::GetDlgCtrlID(hwndChild); // 获取控件ID
			ChangeSize(nID, cx, cy);
			hwndChild = ::GetWindow(hwndChild, GW_HWNDNEXT);

		}
		GetClientRect(&m_rect);
		change_index = 0;

	}

}


void my_parenthesis_match_dlg::OnEnChangeParMatchEdit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


HCURSOR my_parenthesis_match_dlg::OnQueryDragIcon()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	return static_cast<HCURSOR>(m_hIcon);
	//return CDialogEx::OnQueryDragIcon();
}


void my_parenthesis_match_dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}
/*std::string CStringToString(const CString& cstr)
{
	CT2CA pszConvertedAnsiString(cstr);
	std::string str(pszConvertedAnsiString);
	return str;
}*/


void my_parenthesis_match_dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	//GetDlgItemText(IDC_PAR_MATCH_LIST, par_match_edit);

	CT2CA pszConvertedAnsiString(par_match_edit);
	std::string str(pszConvertedAnsiString);
	std::string edit_str = str;
	const char* temp = edit_str.c_str();

	match_list.DeleteAllItems();
	parenthesis_match_fun(temp);
	/*
	* index = 1;

	CDialogEx::OnOK();
	*/
	
}

bool my_parenthesis_match_dlg::parenthesis_match_fun(const char* e)
{
	
	Charlist char_stack;
	CString insert_index;
	CString show_index=_T("");
	bool match_index = 0;
	for (int i = 1; (*e!='\0');)
	{
		UpdateWindow();
		Sleep(100);
		insert_index = _T("扫描到‘");
		insert_index += *e;
		insert_index += _T("’");
		last_row = match_list.GetItemCount();
		match_list.InsertItem(last_row, insert_index);
		show_index += *e;
		match_list.SetItemText(0, 2, show_index);
		if ((*e == '{') )
		{
			insert_index = std::to_string(i).c_str();
			insert_index += _T("号等待匹配");
			match_list.SetItemText(last_row, 1, insert_index);
			char_stack.push('}');
			char_stack.set_index(i);
			i++;
		}
		if ((*e == '['))
		{
			insert_index = std::to_string(i).c_str();
			insert_index += _T("号等待匹配");
			match_list.SetItemText(last_row, 1, insert_index);
			char_stack.push(']');
			char_stack.set_index(i);
			i++;
		}
		if ((*e == '('))
		{
			insert_index = std::to_string(i).c_str();
			insert_index += _T("号等待匹配");
			match_list.SetItemText(last_row, 1, insert_index);
			char_stack.push(')');
			char_stack.set_index(i);
			i++;
		}
		
		if (char_stack.top() == *e)
		{
			match_index = 1;
			last_row = match_list.GetItemCount();
			insert_index = _T("匹配到‘");
			insert_index += *e;
			insert_index += _T("’");
			match_list.InsertItem(last_row, insert_index);
			insert_index = std::to_string(char_stack.get_index()).c_str();
			insert_index += _T("号匹配成功！！！");
			match_list.SetItemText(last_row, 1, insert_index);
			char_stack.pop();
		}
		else if ((*e == '}') || (*e == ']') || (*e == ')'))
		{
			last_row = match_list.GetItemCount();
			insert_index = _T("无法匹配‘");
			insert_index += *e;
			insert_index += _T("’");
			match_list.InsertItem(last_row, insert_index);
			return false;
		}
		e++;
	}
	last_row = match_list.GetItemCount();
	insert_index = _T("扫描完成");
	match_list.InsertItem(last_row, insert_index);
	if (char_stack.return_num() != 0)
	{
		last_row = match_list.GetItemCount();
		/*insert_index = _T("无法匹配到‘");
		insert_index += char_stack.top();
		insert_index += _T("’");*/
		insert_index = _T("无法匹配序号");
		insert_index += std::to_string(char_stack.get_index()).c_str();
		match_list.InsertItem(last_row, insert_index);
		
		//match_list.SetItemText(last_row, 1, insert_index);

		return false;
	}
	if (match_index != 0)
	{
		insert_index = _T("所有括号匹配成功！");
		match_list.SetItemText(last_row, 0, insert_index);
		return true;
	}
	insert_index = _T("没有找到括号哦...");
	match_list.SetItemText(last_row, 0, insert_index);
	return true;
}


void my_parenthesis_match_dlg::OnBnClickedMatchButton()
{
	// TODO: 在此添加控件通知处理程序代码
	
}

void my_parenthesis_match_dlg::list_show()
{
	/*CString insert_index;
	main_list.DeleteAllItems();
	for (size_t i = 0; i < seqlist_ptr->getInstance()->return_num(); i++)
	{
		insert_index = _T("节点");
		insert_index += std::to_string(i + 1).c_str();
		//insert_index = std::to_string(i+1).c_str();//int转Cstring
		last_row = main_list.GetItemCount();
		last_row = main_list.InsertItem(last_row, insert_index);
		insert_index = std::to_string(seqlist_ptr->getInstance()->show(i)).c_str();
		main_list.SetItemText(last_row, 1, insert_index);
	}
	for (size_t i = seqlist_ptr->getInstance()->return_num(); i < seqlist_ptr->getInstance()->return_size(); i++)
	{
		insert_index = _T("节点");
		insert_index += std::to_string(i + 1).c_str();
		//insert_index = std::to_string(i + 1).c_str();//int转Cstring
		last_row = main_list.GetItemCount();
		last_row = main_list.InsertItem(last_row, insert_index);

	}*/
	
}


void my_parenthesis_match_dlg::OnLvnItemchangedParMatchList(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}

// 判断运算符的优先级
int getPriority(char op) {
	if (op == '+' || op == '-') {
		return 1;
	}
	else if (op == '*' || op == '/') {
		return 2;
	}
	return 0;
}
void my_parenthesis_match_dlg::OnBnClickedInfixToButton()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	//GetDlgItemText(IDC_PAR_MATCH_LIST, par_match_edit);

	CT2CA pszConvertedAnsiString(par_match_edit);
	std::string str(pszConvertedAnsiString);
	std::string edit_str = str;
	const char* e = edit_str.c_str();

	match_list.DeleteAllItems();
	
	
	Charlist char_stack;
	CString insert_index;
	CString show_index = _T("");
	CString postfix= _T("");
	bool match_index = 0;

	for (int i = 1; (*e != '\0');)
	{
		UpdateWindow();
		//Sleep(100);
		insert_index = _T("扫描到‘");
		insert_index += *e;
		insert_index += _T("’");
		last_row = match_list.GetItemCount();
		match_list.InsertItem(last_row, insert_index);
		show_index += *e;
		match_list.SetItemText(0, 2, show_index);

		if ((*e >= 'a' && *e <= 'z') || (*e >= 'A' && *e <= 'Z') || (*e >= '0' && *e <= '9')||(*e=='.')) { // 如果是字母或数字，直接加入后缀表达式
			//char_stack += *e;
			postfix += *e;
			match_list.SetItemText(0, 1, postfix);
			
		}
		else if (*e == '(') { // 如果是左括号，入栈
			char_stack.push(*e);
		}
		else if (*e == ')') { // 如果是右括号，将栈中的运算符弹出，加入后缀表达式，直到遇到左括号
			while (char_stack.top() != '(') {
				postfix += char_stack.top();
				char_stack.pop();
				if (char_stack.top() == '\0')
				{
					insert_index = _T("未找到左括号");
					match_list.SetItemText(0, 1, insert_index);
					return;
				}
			}
			char_stack.pop();
		}
		else if((*e == '+')|| (*e == '-') || (*e == '*') || (*e == '/') ) // 如果是运算符
		{
			postfix += ' ';
			match_list.SetItemText(0, 1, postfix);
			while (char_stack.top() != '(' && getPriority(*e) <= getPriority(char_stack.top()))
			{
				
				postfix += char_stack.top();
				char_stack.pop();
			}
			char_stack.push(*e);
		}
		else if (*e == ' ')
		{
		}
		else
		{
			insert_index = _T("非法字符‘");
			insert_index += *e;
			insert_index += _T("’");
			match_list.SetItemText(0, 1, insert_index);
			return;
		}
		e++;
	}
	while (char_stack.top()!='\0') { // 将栈中剩余的运算符加入后缀表达式
		postfix += char_stack.top();
		match_list.SetItemText(0, 1, postfix);
		char_stack.pop();
	}
}

std::string infixToPostfix(std::istringstream& in, Charlist& t) {
	std::string result;
	char op, ch;

	while (in >> ch) {
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || (ch == '.'))
		{
			result += ch;
		}
		else if (ch == '(') {
			// 遇到左括号时，递归调用自身
			t.push('(');
			result += infixToPostfix(in, t) ;
		}
		else if (ch == ')') {
			// 遇到右括号时，返回结果
			while (t.top() != '(') {
				result += t.top();
				t.pop();
				if (t.top() == '\0')
				{
					throw std::runtime_error("未找到左括号");
					//insert_index = _T("未找到左括号");
					//match_list.SetItemText(0, 1, insert_index);
					//return;
				}
			}
			t.pop();
			return result;
		}
		else if (getPriority(ch) > 0) {
			// 遇到操作符时，将其保存下来
			//op = ch;
			result += ' ';
			while (t.top() != '(' && getPriority(ch) <= getPriority(t.top()))
			{

				result += t.top();
				t.pop();
			}
			t.push(ch);
		}
		else if (ch == ' ')
		{
		}
		else {
			throw std::runtime_error("非法字符");
		}
	}

	return result;
}

void my_parenthesis_match_dlg::OnBnClickedInfixToReButton()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	//GetDlgItemText(IDC_PAR_MATCH_LIST, par_match_edit);

	CT2CA pszConvertedAnsiString(par_match_edit);
	std::string str(pszConvertedAnsiString);
	std::string edit_str = str;
	//const char* e = edit_str.c_str();

	match_list.DeleteAllItems();


	Charlist char_stack;
	CString insert_index;

	//std::string exp = "(a+b)*(c+d)/320";
	std::istringstream in(str);
	try {
		insert_index = infixToPostfix(in, char_stack).c_str();
	}
	catch (const std::exception& e) {
		insert_index = e.what();
	}
	while (char_stack.top() != '\0') { // 将栈中剩余的运算符加入后缀表达式
		insert_index += char_stack.top();
		char_stack.pop();
	}
	match_list.InsertItem(0, _T(""));
	match_list.SetItemText(0, 1, insert_index);

}
