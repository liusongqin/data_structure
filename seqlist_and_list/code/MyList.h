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
	//头节点
	ListNode* first = nullptr;
	//尾节点
	ListNode* end = nullptr;
	//用来遍历用的
	ListNode* list = nullptr;
	//ListNode* inverse_end = nullptr;//用来逆转用的
	int num;//链表节点个数
	static MyList* Instance;
public:
	MyList() ;
	MyList(int number);
	~MyList();
	static MyList* getInstance();
	void setInstance(int n);
	bool insert(int n, int number);//n代表位置,number代表元素
	bool insert(int target_n, int number, bool index_juge);//在某个元素后面插入
	//ListNode* search(int number);
	bool del(int n,bool index);//根据位置删除
	bool del(int n);//根据元素删除
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
	//栈的功能

};

struct CharNode
{
	char data;
	int index=0;//序号
	CharNode* link = nullptr;
};

class Charlist
{
private:
	//头节点
	CharNode* first = nullptr;
	//尾节点
	int num=0;//节点个数
public:
	~Charlist();
	bool pop();
	bool push(char c);
	bool set_index(int& num);
	int get_index();
	char top();
	int return_num() { return num; };
};