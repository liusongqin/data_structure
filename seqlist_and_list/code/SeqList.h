#pragma once
#include"linear_list.h"
class SeqList :public linear_list<int>
{
private:
	int* list = nullptr;//用于遍历的指针
	int* first = nullptr;
	int* end = nullptr;//指向实际元素的最后一个位置
	int num;//表中的数据元素的个数
	int size;//表的大小 
	static SeqList* Instance;

public:
	SeqList(int t_size);//需要申请的大小
	SeqList(int n, int t_size);//首节点元素，需要申请的大小
	~SeqList();
	static SeqList* getInstance();
	bool setInstance(int n, int t_size);
	bool insert(int n, int number);
	bool insert(int target_n, int number, bool index_juge);//在某个元素后面插入
	bool del(int n,bool index);//用来区分两个del
	bool del(int number);//根据元素来删除
	int show(int show_num);
	bool add(int number);
	int return_num()
	{
		return num;
	}
	int return_size()
	{
		return size;
	}
};

