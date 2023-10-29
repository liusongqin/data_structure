#include"pch.h"
#include<iostream>
#include "MyList.h"


MyList* MyList::Instance = 0;

MyList::MyList()//默认构造只构造空表头
{
	first = new ListNode;//空表头
	first->data = 0;
	first->link = nullptr;
	end = first;
	num = 1;
}

MyList::MyList(int number)//只初始化空表头和首节点
{
	first = new ListNode;
	first->link= new ListNode;//空表头
	first->data = 0;
	first->link->data = number;
	first->link->link = nullptr;
	end = first->link;
	num= 2;
}

MyList::~MyList()
{
	if (Instance)
	{
		/*
		delete[] first;
		Instance->num = 0;
		Instance->size = 0;
		Instance->first = nullptr;
		//delete[] Instance;
		*/
		for (size_t i = 0; i < num-1; i++)
		{
			Instance->del(1);
		}
		Instance->num = 0;
		num = 0;
		delete Instance->first;
		Instance->first = nullptr;

	}
	Instance = nullptr;
	
}

MyList* MyList::getInstance()
{
	if (!Instance)
	{
		Instance = new MyList();//如果用户没有初始化，就自动构造一个空表头
	}
	return Instance;
}

void MyList::setInstance(int n)
{
	Instance = new MyList(n);
}

bool MyList::insert(int n, int number)
{
	if ((n < num) && (n >= 0)) {
		ListNode* newnode=new ListNode;
		newnode->data = number;
		list = first;
		for (size_t i = 0; i < n ; i++)
		{
			list = list->link;
		}

		//int* tempptr;//用来存end之前的指针
		//int* tempend;//记录end的位置
		//tempend = end;
		if (n == (num-1))
		{
			list->link = newnode;
			num++;
			end = list->link;
		}
		else
		{
			newnode->link = list->link;
			list->link = newnode;
			num++;

		}
		return true;
	}
	else {
		return false;
	}
}

bool MyList::insert(int target_n, int number, bool index_juge)
{
	list = first->link;
	int count = 0;
	bool index = 0;//检测是否查到
	for (size_t i = 1; i < num; i++)
	{
		if ((list->data) == target_n)
		{
			count = i;
			index = 1;
			break;
		}
		list = list->link;
	}
	if (index)
	{
		insert(count, number);
		return true;
	}
	return false;
}
/*ListNode* MyList::search(int n)
{
	list = first->link;
	for (size_t i = 0; i < num; i++)
	{
		if ((list->data) == n)
		{
			return list;
		}
	}
	return nullptr;
}*/


bool MyList::del(int n, bool index)
{
	if ((n < num) && (n > 0)) {
		list = first;
		for (size_t i = 0; i < n - 1; i++)
		{
			list = list->link;
		}
		ListNode* delptr;

		//int* tempptr;//用来存end之前的指针
		//int* tempend;//记录end的位置
		//tempend = end;
		if (!(list->link->link))
		{
			delete list->link;
			end=list;
			num--;

		}
		else
		{
			delptr = list->link;
			list->link = list->link->link;
			delete delptr;
			delptr = nullptr;
			num--;
		}
		return true;
	}
	else {
		return false;
	}
}

bool MyList::del(int number)
{
	list = first->link;
	bool index = 0;//是否进行了删除操作
	for (size_t i = 1; i < num ; i++)
	{
		if (list->data == number)
		{
			
			index = del(i, 1);
			i--;
		}
		list = list->link;
		
	}
	if (index)
	{
		return true;
	}
	else
	{
		return false;

	}
}

int MyList::show(int node_num)
{
	list = first;
	std::cout << std::endl;
	for (size_t i = 0; i < node_num; i++)
	{
		//std::cout << "第" << i + 1 << "个位置上是" << list->data << std::endl;
		list = list->link;
	}
	return list->data;
}

ListNode* MyList::get_node_ptr(int node_num)
{
	list = first;
	std::cout << std::endl;
	for (size_t i = 0; i < node_num; i++)
	{
		//std::cout << "第" << i + 1 << "个位置上是" << list->data << std::endl;
		list = list->link;
	}
	return list;
}

bool MyList::add(int number)
{
	list = first;
	end->link = new ListNode;
	end = end->link;
	end->data = number;
	num++;
	return true;
}
/*//记录原始first
	ListNode* inverse_first = first;
	int j=0;
	for (size_t i = 1; i < num-1; i++)
	{
		//摘取最后一个节点到前面来
		list = first->link;
		first->link = end;
		end->link = list;
		first = end;
		//遍历到新链条的最后一位，找end；
		end = inverse_first;
		for (j = 1; j < num; j++)
		{
			end= end->link;
		}
		end->link = nullptr;
	}
	first = inverse_first;
	inverse_first = nullptr;*/
//要不想影响空表的话，就把下面的first改成first->link
void MyList::inverse()
{
	//原链表栈和新链表栈的对应的节点的物理地址是一样的
	//只是为了方便理解将其抽象为两个栈

	//新的链表栈的首节点
	ListNode* top_inverse=nullptr;
	//将原本的链表栈当作栈；
	ListNode*  top_current = first;
	//用来中转的指针
	ListNode* temp_ptr = nullptr;
	end = first;
	//如果原链表已经空了就停止循环
	
	for (size_t i = 0; (top_current!=nullptr); i++)
	{
		temp_ptr = top_current;
		//原链表栈出栈
		top_current = top_current->link;
		temp_ptr->link = top_inverse;//新链表栈进栈
		top_inverse = temp_ptr;
	}
	first = top_inverse;//将first指向已经逆转好的链表
	top_inverse = nullptr;
	top_current = nullptr;
	temp_ptr = nullptr;//防止野指针

	/*
	std::stack<ListNode*> s;
	while (first)
	{
		s.push(first);//将地址进栈
		first = first->link;
	}
	end = s.top();
	first = end;
	s.pop();
	while (!s.empty())
	{
		end->link= s.top();
		s.pop();//出栈
		end = end->link;
	}
	end->link = nullptr;
	*/
	
}

Charlist::~Charlist()
{
	for (size_t i = 0; i < num; )
	{
		pop();
	}
}

bool Charlist::pop()
{
	if (num==0)
	{
		return false;
	}
	CharNode* del_ptr = nullptr;
	del_ptr = first;
	first = first->link;
	del_ptr->link = nullptr;
	delete del_ptr;
	num--;
}

bool Charlist::push(char c)
{
	CharNode* newnode = new CharNode;
	newnode->data = c;
	newnode->link = first;
	first = newnode;
	num++;
	return true;
}

bool Charlist::set_index(int& num)
{
	first->index = num;
	return true;
}

int Charlist::get_index()
{
	return first->index;
}


char Charlist::top()
{
	if (first == nullptr)
	{
		return '\0';
	}
	return first->data;
}
