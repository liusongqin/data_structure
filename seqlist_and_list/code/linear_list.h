#pragma once
template<class T>
class linear_list
{
protected:
	T* list = nullptr;//用于遍历的指针
	T* first = nullptr;
	T* end = nullptr;//指向实际元素的最后一个位置
	//int num;//表中的数据元素的个数
public:
	linear_list() {};//需要申请的大小
	~linear_list() {};
	virtual bool insert(int n, int number) = 0;
	virtual bool del(int n, bool index) = 0;//用来区分两个del,这个是根据位置来删除
	virtual bool del(int number) = 0;//根据元素来删除
	virtual int show(int show_num) = 0;


};

