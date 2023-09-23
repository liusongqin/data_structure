#pragma once
#include"CircLinkNode.h"
class CircList {
private:
	//�����ඨ��
	CircLinkNode* first, * last;  //ͷָ��, βָ��
public:
	CircList(const int x);//���캯��
	CircList(CircList& L);//���ƹ��캯��
	//��������
	~CircList();
	//����������
	int Length() const;
	bool IsEmpty() { return first->link == first; }
	//�б�շ�
	CircLinkNode * getHead() const;
	//���ر�ͷ����ַ
	void setHead(CircLinkNode * p);
	//���ñ�ͷ����ַ
	CircLinkNode * Search(int x); //����
	CircLinkNode * Locate(int i);//��λ
	int getData(int i) ;
	void setData(int i, int x);
	bool Insert(int i, int x);
	bool Remove(int i, int& x);
};


