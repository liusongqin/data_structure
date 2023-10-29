#include"pch.h"
#include<iostream>
#include "MyList.h"


MyList* MyList::Instance = 0;

MyList::MyList()//Ĭ�Ϲ���ֻ����ձ�ͷ
{
	first = new ListNode;//�ձ�ͷ
	first->data = 0;
	first->link = nullptr;
	end = first;
	num = 1;
}

MyList::MyList(int number)//ֻ��ʼ���ձ�ͷ���׽ڵ�
{
	first = new ListNode;
	first->link= new ListNode;//�ձ�ͷ
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
		Instance = new MyList();//����û�û�г�ʼ�������Զ�����һ���ձ�ͷ
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

		//int* tempptr;//������end֮ǰ��ָ��
		//int* tempend;//��¼end��λ��
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
	bool index = 0;//����Ƿ�鵽
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

		//int* tempptr;//������end֮ǰ��ָ��
		//int* tempend;//��¼end��λ��
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
	bool index = 0;//�Ƿ������ɾ������
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
		//std::cout << "��" << i + 1 << "��λ������" << list->data << std::endl;
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
		//std::cout << "��" << i + 1 << "��λ������" << list->data << std::endl;
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
/*//��¼ԭʼfirst
	ListNode* inverse_first = first;
	int j=0;
	for (size_t i = 1; i < num-1; i++)
	{
		//ժȡ���һ���ڵ㵽ǰ����
		list = first->link;
		first->link = end;
		end->link = list;
		first = end;
		//�����������������һλ����end��
		end = inverse_first;
		for (j = 1; j < num; j++)
		{
			end= end->link;
		}
		end->link = nullptr;
	}
	first = inverse_first;
	inverse_first = nullptr;*/
//Ҫ����Ӱ��ձ�Ļ����Ͱ������first�ĳ�first->link
void MyList::inverse()
{
	//ԭ����ջ��������ջ�Ķ�Ӧ�Ľڵ�������ַ��һ����
	//ֻ��Ϊ�˷�����⽫�����Ϊ����ջ

	//�µ�����ջ���׽ڵ�
	ListNode* top_inverse=nullptr;
	//��ԭ��������ջ����ջ��
	ListNode*  top_current = first;
	//������ת��ָ��
	ListNode* temp_ptr = nullptr;
	end = first;
	//���ԭ�����Ѿ����˾�ֹͣѭ��
	
	for (size_t i = 0; (top_current!=nullptr); i++)
	{
		temp_ptr = top_current;
		//ԭ����ջ��ջ
		top_current = top_current->link;
		temp_ptr->link = top_inverse;//������ջ��ջ
		top_inverse = temp_ptr;
	}
	first = top_inverse;//��firstָ���Ѿ���ת�õ�����
	top_inverse = nullptr;
	top_current = nullptr;
	temp_ptr = nullptr;//��ֹҰָ��

	/*
	std::stack<ListNode*> s;
	while (first)
	{
		s.push(first);//����ַ��ջ
		first = first->link;
	}
	end = s.top();
	first = end;
	s.pop();
	while (!s.empty())
	{
		end->link= s.top();
		s.pop();//��ջ
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
