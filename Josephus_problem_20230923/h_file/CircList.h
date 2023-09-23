#pragma once
#include"CircLinkNode.h"
class CircList {
private:
	//链表类定义
	CircLinkNode* first, * last;  //头指针, 尾指针
public:
	CircList(const int x)
	{
		first = new CircLinkNode;
		//CircLinkNode* newcode = new CircLinkNode;//空表头
		//newcode->data = x;//真正的节点
		first->link = first;
		first->data = x;
	};//构造函数
	CircList(CircList& L)
	{

		if (L.first == nullptr) {
			first = nullptr;
		}
		else {
			first = new CircLinkNode ;  // 创建新的头节点
			first->link = new CircLinkNode ;  // 创建新的数据节点

			CircLinkNode * current = L.first->link;  // 当前遍历到的原链表中的节点
			CircLinkNode * newCurrent = first->link;  // 当前遍历到的新链表中的节点
			while (current != L.first) {  // 遍历原链表中的所有数据节点
				newCurrent->data = current->data;  // 复制数据

				current = current->link;  // 移动到下一个节点

				if (current != L.first) {  // 如果还有更多的数据节点需要复制
					newCurrent->link = new CircLinkNode;  // 创建新的数据节点
					newCurrent = newCurrent->link;  // 移动到下一个节点
				}
				else {
					newCurrent->link = first;  // 最后一个数据节点指向头节点，形成循环
				}
			}
			newCurrent = last;

		}

	};//复制构造函数
	//析构函数
	~CircList() 
	{
			if (first != nullptr) {
			
				CircLinkNode * current = first->link;  // 当前遍历到的节点
				while (current != first) {  // 遍历所有数据节点
					CircLinkNode * nextNode = current->link;  // 保存下一个节点的指针
					delete current;  // 删除当前节点
					current = nextNode;  // 移动到下一个节点
				}
				delete first;  // 删除头节点
			}
	}

	//计算链表长度
	int Length() const
	{
		if (first == nullptr) {
			return 0;  // 如果头节点为 nullptr，那么链表为空，长度为0
		}
		else {
			int length = 0;
			CircLinkNode * current = first->link;  // 当前遍历到的节点
			while (current != first) {  // 遍历所有数据节点
				length++;  // 计数器加1
				current = current->link;  // 移动到下一个节点
			}
			return length;  // 返回计数器的值，即链表的长度
		}
	};
	

	bool IsEmpty() { return first->link == first; }
	//判表空否
	CircLinkNode * getHead() const
	{
		return first;
	}
		;
	//返回表头结点地址
	void setHead(CircLinkNode * p)
	{
		first = p;
	};
	//设置表头结点地址
	CircLinkNode * Search(int x)
	{
		CircLinkNode * p = first;
		while (p != nullptr) {
			if (p->data == x) {
				return p;
			}
			p = p->link;
		}
		return nullptr;
	}; //搜索
	CircLinkNode * Locate(int i)
	{
		if (i < 0) {
			return nullptr;
		}
		CircLinkNode * p = first;
		int index = 0;
		while (p != nullptr && index < i) {
			p = p->link;//一个一个按顺序查找
			index++;
		}
		return p;

	}
		;//定位
	int getData(int i) 
	{
		return Locate(i)->data;
	};
	void setData(int i, int x)
	{
		
		CircLinkNode * p = Locate(i);
		p->data = x;
	};
	bool Insert(int i, int x)
	{
		if (i < 0) {
			return false;
		}
		if (i == 0) {
			first = new CircLinkNode (x, first);//插入一个新节点，很巧妙的办法
			return true;
		}
		CircLinkNode * p = Locate(i - 1);//锁定要插入的前面一个节点
		if (p == nullptr) {
			return false;
		}
		p->link = new CircLinkNode (x, p->link);
		return true;
	};
	bool Remove(int i, int& x)
	{
		if (i < 0) {
			return false;
		}
		CircLinkNode * p;
		if (i == 0) {
			p = first;
			if (first != nullptr) {
				first = first->link;
			}
		}
		else {
			CircLinkNode * prev = Locate(i - 1);
			if (prev == nullptr || prev->link == nullptr) //查找的数出界
			{
				return false;
			}
			p = prev->link;
			prev->link = p->link;
		}
		//在这里一起释放
		if (p != nullptr) {
			x = p->data;
			delete p;
			return true;
		}
		else {
			return false;
		}
	};
};


