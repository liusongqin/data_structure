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
    
    // 创建一个BinaryTree对象
    BinaryTree bt;

    // 定义前序和中序遍历序列
    //vector<int> preorder = { 3, 9, 20, 15 ,8, 7 };
    //vector<int> inorder = { 9, 3, 8, 15, 20, 7 };
    //std::vector<int> preorder;
    //std::vector<int> inorder;

    initgraph(1080, 600);

    char input[256];
    std::vector<int> preorder;
    std::vector<int> inorder;
    ege::outtextxy(50, 50, "请输入一系列整数，以空格分隔：");
    ege::inputbox_getline("输入前序序列", "请输入一系列整数，以空格分隔：", input, sizeof(input));  // 获取用户输入

    std::istringstream iss(input);
    int num;
    while (iss >> num) {  // 将输入的字符串转换为整数并存入vector中
        preorder.push_back(num);
    }
    ege::outtextxy(50, 50, "请输入一系列整数，以空格分隔：");
    ege::inputbox_getline("输入后序序列", "请输入一系列整数，以空格分隔：", input, sizeof(input));  // 获取用户输入

    std::istringstream iss_2(input);
    while (iss_2 >> num) {  // 将输入的字符串转换为整数并存入vector中
        inorder.push_back(num);
    }
    if (checkPreorderInorder(preorder, inorder))
    {
        // 构建二叉树
        Node* root = bt.buildTree(preorder, inorder);
    }
    else {
        ege::outtextxy(540, 300, "错误,您的输入有误");
    }
    

    getch();
    closegraph();

    return 0;
}
