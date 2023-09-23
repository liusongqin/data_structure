#include <iostream>
#include"CircList.h"
#include"CircLinkNode.h"

using namespace std;
void Josephus(CircList& Js, int n, int m) {
	CircLinkNode* p = Js.getHead();
	CircLinkNode* pre = NULL;
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 1; j < m; j++)
		{
			pre = p; 
			p = p->link;
		}
		//ִ��n-1��
	   //��m-1����
		cout << "���е�����" << p->data << endl;
		pre->link = p->link;  
		delete p;
		p = pre->link;
	}
	Js.setHead(nullptr);
};

void main() {
	
	int i, n,m;
	cout << "������Ϸ�������ͱ������: ";
	cin >> n >> m;
	CircList clist(1);
	for (i = 1; i <n; i++) clist.Insert(i,i+1);    //Լɪ��
	Josephus(clist, n, m);
	//���Լɪ������
	system("pause");
}
