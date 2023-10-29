#include"pch.h"
#include<iostream>
#include <afxstr.h>
#include "SeqList.h"

SeqList* SeqList::Instance = 0;

SeqList::SeqList(int t_size)
{
	num = 0;
	size = t_size;
	first = new int[t_size+1] {0};
	list = first;
	for (size_t i = 0; i < t_size; i++)
	{
		list++;
	}
	end = list;
	list = first;
}

SeqList::SeqList(int n,int t_size)
{

	
	num = 1;
	size = t_size;
	first = new int[t_size+1] {0};
	first[0] = n;
	list = first;
	for (size_t i = 0; i < t_size; i++)
	{
		list++;
	}
	end = list;
	list = first;
}

SeqList::~SeqList()
{
	/*list = first;
	while (list!=(end++))
	{
		delete list;
		list++;
		num--;
	}
	list = nullptr;
	first = nullptr;
	end = nullptr;*/
	if (Instance)
	{
		delete[] Instance->first;
		Instance->num = 0;
		Instance->size = 0;
		Instance->first = nullptr;
		//delete[] Instance;
	}

}

SeqList* SeqList::getInstance()
{
	if (!Instance)
	{
		Instance = new SeqList(10);//����û�û�г�ʼ�������Զ�����10���ռ�
	}
	return Instance;
}

bool SeqList::setInstance(int n,int t_size)
{
	if (t_size > 0)
	{
		Instance = new SeqList(n, t_size);
		return true;
	}
	else
	{
		return false;
	}
}

bool SeqList::insert(int n, int number)//�����λ�ú�����
{
	list = first;
	if (n < 0 || n > num) {
		return false; // ����λ����Ч
	}
	if (num >= size) {
		return false; // ������
	}
	for (size_t i = num; i > n; --i) {
		list[i] = list[i - 1]; // ��Ԫ������ƶ�
	}
	list[n] = number; // ������Ԫ��
	++num; // ����Ԫ������
	list = first;
	return true;
	/*if (num >= size) {
		return false; // ������
	}
	if (n < 0 || n > num) {
		return false; // ����λ����Ч
	}
	end++;
	list = first;
	for (size_t i = 0; i < n; i++)
	{
			list++;
	}
	int* tempptr;//��¼Ҫ����Ԫ�ص�λ��
	int temp;
	tempptr = list;
	list = end;

	//int* tempptr;//������end֮ǰ��ָ��
	//int* tempend;//��¼end��λ��
	//tempend = end;
	list--;
	do
	{
		temp = *list;
		list++;
		*(list) = temp;
		list--;
		list--;
	}//��Ԫ�غ���
	while (list == tempptr);
	*tempptr = number;
	num++;
	return true;*/
	
}

bool SeqList::insert(int target_n, int number, bool index_juge)
{
	list = first;
	bool index = 0;//�Ƿ�����˲������
	for (size_t i = 1; i < (num + 1); i++)
	{
		if (list[i - 1] == target_n)
		{
			
			index = insert(i, number);

		}
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

bool SeqList::del(int n, bool index)
{
	list = first;
	if (n <= 0 || n > num) {
		return false; // ɾ��λ����Ч
	}
	for (size_t i = n; i < num+1 ; i++) {
		list[i-1] = list[i]; // ��Ԫ����ǰ�ƶ�
	}
	--num; // ����Ԫ������
	return true;
	/*if ((n < num + 1) && (n > 0)) {
		list = first;
		for (size_t i = 0; i < n -1; i++)
		{
			list++;
		}
		int temp;

		//int* tempptr;//������end֮ǰ��ָ��
		//int* tempend;//��¼end��λ��
		//tempend = end;
		if (n == num)
		{
			list--;
			end = list;
			num--;

		}
		else 
		{
			list++;
			do
			{
				temp = *list;
				list--;
				*(list) = temp;
				list++;
				list++;
			}//��Ԫ�غ���
			while (list == (end++));
			list--;
			list--;

			end = list;
			num--;
		}
		
		return true;
	}
	else {
		return false;
	}*/
	

}

bool SeqList::del(int number)
{
	
	/*int i, d = 0;
	for (i = 0; i < num - d; i++) {
		while (list[i + d] == number) {
			d++;
		}
		list[i] = list[i + d];
	}
	num -= d;*/
	list = first;
	bool index=0;//�Ƿ������ɾ������
	for (size_t i = 1; i < (num+1); i++)
	{
		if (list[i-1] == number)
		{
			del(i,1);
			index = 1;
			i--;
			
		}
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

int SeqList::show(int show_num)
{
	list = first;
	std::cout << std::endl;
	for (size_t i = 0; i <= show_num; i++)
	{
		if (i == show_num)
		{
			//std::cout << "��" << i + 1 << "��λ������" << *list << std::endl;
			
			return *list;
		}
		list++;
		
	}
	list = first;
	return int();
}

bool SeqList::add(int number)
{
	list = first;
	if (num >= size) {
		return false; // ������
	}
	list[num] = number; // �ڱ�β�����Ԫ��
	++num; // ����Ԫ������
	return true;
	
}
