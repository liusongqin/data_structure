#pragma once
template<class T>
class linear_list
{
protected:
	T* list = nullptr;//���ڱ�����ָ��
	T* first = nullptr;
	T* end = nullptr;//ָ��ʵ��Ԫ�ص����һ��λ��
	//int num;//���е�����Ԫ�صĸ���
public:
	linear_list() {};//��Ҫ����Ĵ�С
	~linear_list() {};
	virtual bool insert(int n, int number) = 0;
	virtual bool del(int n, bool index) = 0;//������������del,����Ǹ���λ����ɾ��
	virtual bool del(int number) = 0;//����Ԫ����ɾ��
	virtual int show(int show_num) = 0;


};

