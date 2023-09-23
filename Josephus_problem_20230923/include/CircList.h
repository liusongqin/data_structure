#pragma once
#include"CircLinkNode.h"
class CircList {
private:
	//链表类定义
	CircLinkNode* first, * last;  //头指针, 尾指针
public:
	CircList(const int x);//构造函数
	CircList(CircList& L);//复制构造函数
	//析构函数
	~CircList();
	//计算链表长度
	int Length() const;
	bool IsEmpty() { return first->link == first; }
	//判表空否
	CircLinkNode * getHead() const;
	//返回表头结点地址
	void setHead(CircLinkNode * p);
	//设置表头结点地址
	CircLinkNode * Search(int x); //搜索
	CircLinkNode * Locate(int i);//定位
	int getData(int i) ;
	void setData(int i, int x);
	bool Insert(int i, int x);
	bool Remove(int i, int& x);
};


