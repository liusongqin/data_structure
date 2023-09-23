#pragma once
struct CircLinkNode
{
	int data;
	CircLinkNode* link;
	//链表结点类定义
	CircLinkNode(CircLinkNode* next = NULL)
	{
		link = next;
	}
	CircLinkNode(int d, CircLinkNode* next = NULL)
	{
		data = d; link = next;
	}
	/*bool Operator == (T x)
	{
		return data.key == x.key;
	}
	bool Operator!= (T x)
	{
		return data.key != x.key;
	}*/
};