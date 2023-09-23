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
		//执行n-1次
	   //数m-1个人
		cout << "出列的人是" << p->data << endl;
		pre->link = p->link;  
		delete p;
		p = pre->link;
	}
	Js.setHead(nullptr);
};

void main() {
	
	int i, n,m;
	cout << "输入游戏者人数和报数间隔: ";
	cin >> n >> m;
	CircList clist(1);
	for (i = 1; i <n; i++) clist.Insert(i,i+1);    //约瑟夫环
	Josephus(clist, n, m);
	//解决约瑟夫问题
	system("pause");
}
