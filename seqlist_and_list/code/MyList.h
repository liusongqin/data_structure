#pragma once
#include"linear_list.h"
//#include<stack>
struct ListNode
{
	int data;
	ListNode* link=nullptr;
};



class MyList :public linear_list<ListNode>
{
private:
	//ͷ�ڵ�
	ListNode* first = nullptr;
	//β�ڵ�
	ListNode* end = nullptr;
	//���������õ�
	ListNode* list = nullptr;
	//ListNode* inverse_end = nullptr;//������ת�õ�
	int num;//����ڵ����
	static MyList* Instance;
public:
	MyList() ;
	MyList(int number);
	~MyList();
	static MyList* getInstance();
	void setInstance(int n);
	bool insert(int n, int number);//n����λ��,number����Ԫ��
	bool insert(int target_n, int number, bool index_juge);//��ĳ��Ԫ�غ������
	//ListNode* search(int number);
	bool del(int n,bool index);//����λ��ɾ��
	bool del(int n);//����Ԫ��ɾ��
	int show(int show_num);
	ListNode* get_node_ptr(int node_num);
	ListNode* return_list(){return list;}
	ListNode* return_first() { return first; }
	ListNode* return_end() { return end; }
	int return_num()
	{
		return num;
	}
	bool add(int number);
	void inverse();
	//ջ�Ĺ���

};

struct CharNode
{
	char data;
	int index=0;//���
	CharNode* link = nullptr;
};

class Charlist
{
private:
	//ͷ�ڵ�
	CharNode* first = nullptr;
	//β�ڵ�
	int num=0;//�ڵ����
public:
	~Charlist();
	bool pop();
	bool push(char c);
	bool set_index(int& num);
	int get_index();
	char top();
	int return_num() { return num; };
};