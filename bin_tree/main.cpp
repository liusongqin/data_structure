#include"Binary_Tree.h"
#include <iostream>
#include <vector>
#include <unordered_set>
#include<graphics.h>
#include <ege.h>
#include <sstream>
#include <unordered_map>
using namespace std;

bool checkPreorderInorder(const std::vector<int>& preorder, const std::vector<int>& inorder) {
    if (preorder.size() != inorder.size()) {
        return false;
    }

    std::unordered_map<int, int> count;
    for (int num : preorder) {
        ++count[num];
    }

    for (int num : inorder) {
        if (--count[num] < 0) {
            return false;
        }
    }

    return true;
}

int main() {
    
    // ����һ��BinaryTree����
    BinaryTree bt;

    // ����ǰ��������������
    //vector<int> preorder = { 3, 9, 20, 15 ,8, 7 };
    //vector<int> inorder = { 9, 3, 8, 15, 20, 7 };
    //std::vector<int> preorder;
    //std::vector<int> inorder;

    initgraph(1080, 600);

    char input[256];
    std::vector<int> preorder;
    std::vector<int> inorder;
    ege::outtextxy(50, 50, "������һϵ���������Կո�ָ���");
    ege::inputbox_getline("����ǰ������", "������һϵ���������Կո�ָ���", input, sizeof(input));  // ��ȡ�û�����

    std::istringstream iss(input);
    int num;
    while (iss >> num) {  // ��������ַ���ת��Ϊ����������vector��
        preorder.push_back(num);
    }
    ege::outtextxy(50, 50, "������һϵ���������Կո�ָ���");
    ege::inputbox_getline("�����������", "������һϵ���������Կո�ָ���", input, sizeof(input));  // ��ȡ�û�����

    std::istringstream iss_2(input);
    while (iss_2 >> num) {  // ��������ַ���ת��Ϊ����������vector��
        inorder.push_back(num);
    }
    if (checkPreorderInorder(preorder, inorder))
    {
        // ����������
        Node* root = bt.buildTree(preorder, inorder);
    }
    else {
        ege::outtextxy(540, 300, "����,������������");
    }
    

    getch();
    closegraph();

    return 0;
}
