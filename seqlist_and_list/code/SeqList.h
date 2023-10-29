#pragma once
#include"linear_list.h"
class SeqList :public linear_list<int>
{
private:
	int* list = nullptr;//���ڱ�����ָ��
	int* first = nullptr;
	int* end = nullptr;//ָ��ʵ��Ԫ�ص����һ��λ��
	int num;//���е�����Ԫ�صĸ���
	int size;//��Ĵ�С 
	static SeqList* Instance;

public:
	SeqList(int t_size);//��Ҫ����Ĵ�С
	SeqList(int n, int t_size);//�׽ڵ�Ԫ�أ���Ҫ����Ĵ�С
	~SeqList();
	static SeqList* getInstance();
	bool setInstance(int n, int t_size);
	bool insert(int n, int number);
	bool insert(int target_n, int number, bool index_juge);//��ĳ��Ԫ�غ������
	bool del(int n,bool index);//������������del
	bool del(int number);//����Ԫ����ɾ��
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

