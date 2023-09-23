#pragma once
#include"CircLinkNode.h"
class CircList {
private:
	//�����ඨ��
	CircLinkNode* first, * last;  //ͷָ��, βָ��
public:
	CircList(const int x)
	{
		first = new CircLinkNode;
		//CircLinkNode* newcode = new CircLinkNode;//�ձ�ͷ
		//newcode->data = x;//�����Ľڵ�
		first->link = first;
		first->data = x;
	};//���캯��
	CircList(CircList& L)
	{

		if (L.first == nullptr) {
			first = nullptr;
		}
		else {
			first = new CircLinkNode ;  // �����µ�ͷ�ڵ�
			first->link = new CircLinkNode ;  // �����µ����ݽڵ�

			CircLinkNode * current = L.first->link;  // ��ǰ��������ԭ�����еĽڵ�
			CircLinkNode * newCurrent = first->link;  // ��ǰ���������������еĽڵ�
			while (current != L.first) {  // ����ԭ�����е��������ݽڵ�
				newCurrent->data = current->data;  // ��������

				current = current->link;  // �ƶ�����һ���ڵ�

				if (current != L.first) {  // ������и�������ݽڵ���Ҫ����
					newCurrent->link = new CircLinkNode;  // �����µ����ݽڵ�
					newCurrent = newCurrent->link;  // �ƶ�����һ���ڵ�
				}
				else {
					newCurrent->link = first;  // ���һ�����ݽڵ�ָ��ͷ�ڵ㣬�γ�ѭ��
				}
			}
			newCurrent = last;

		}

	};//���ƹ��캯��
	//��������
	~CircList() 
	{
			if (first != nullptr) {
			
				CircLinkNode * current = first->link;  // ��ǰ�������Ľڵ�
				while (current != first) {  // �����������ݽڵ�
					CircLinkNode * nextNode = current->link;  // ������һ���ڵ��ָ��
					delete current;  // ɾ����ǰ�ڵ�
					current = nextNode;  // �ƶ�����һ���ڵ�
				}
				delete first;  // ɾ��ͷ�ڵ�
			}
	}

	//����������
	int Length() const
	{
		if (first == nullptr) {
			return 0;  // ���ͷ�ڵ�Ϊ nullptr����ô����Ϊ�գ�����Ϊ0
		}
		else {
			int length = 0;
			CircLinkNode * current = first->link;  // ��ǰ�������Ľڵ�
			while (current != first) {  // �����������ݽڵ�
				length++;  // ��������1
				current = current->link;  // �ƶ�����һ���ڵ�
			}
			return length;  // ���ؼ�������ֵ��������ĳ���
		}
	};
	

	bool IsEmpty() { return first->link == first; }
	//�б�շ�
	CircLinkNode * getHead() const
	{
		return first;
	}
		;
	//���ر�ͷ����ַ
	void setHead(CircLinkNode * p)
	{
		first = p;
	};
	//���ñ�ͷ����ַ
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
	}; //����
	CircLinkNode * Locate(int i)
	{
		if (i < 0) {
			return nullptr;
		}
		CircLinkNode * p = first;
		int index = 0;
		while (p != nullptr && index < i) {
			p = p->link;//һ��һ����˳�����
			index++;
		}
		return p;

	}
		;//��λ
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
			first = new CircLinkNode (x, first);//����һ���½ڵ㣬������İ취
			return true;
		}
		CircLinkNode * p = Locate(i - 1);//����Ҫ�����ǰ��һ���ڵ�
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
			if (prev == nullptr || prev->link == nullptr) //���ҵ�������
			{
				return false;
			}
			p = prev->link;
			prev->link = p->link;
		}
		//������һ���ͷ�
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


