#pragma once
#include"linear_list.h"
struct ListNode
{
	int data;
	ListNode* link=nullptr;
};
class MyList :public linear_list<ListNode>
{
private:
	ListNode* first = nullptr;
	ListNode* end = nullptr;
	ListNode* list = nullptr;//���������õ�
	//ListNode* inverse_end = nullptr;//������ת�õ�
	int num;
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

};

