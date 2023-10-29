#include <vector>
#include<graphics.h>
#include <string>
//#include <windows.h>
using namespace std;


// 定义节点结构
struct Node {
    int val;  // 节点值
    Node* left, * right, * parent;  // 左子节点、右子节点和父节点指针
    Node(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}  // 构造函数
};



// 定义二叉树类
class BinaryTree {
private:
    vector<int> preorder, inorder;  // 前序和中序遍历序列
    Node* base_root = NULL;
    bool index = 0;
    // 在给定的范围内搜索一个值在向量中的位置(找索引)
    int search(vector<int>& vec, int start, int end, int value) {
        for (int i = start; i <= end; i++) {
            if (vec[i] == value) {
                return i;
            }
        }
        return -1;
    }

    // 递归地构建二叉树
    Node* buildTree(int preStart, int inStart, int inEnd, Node* parent, bool index_LorR);

public:
    Node* buildTree(vector<int>& preorderInput, vector<int>& inorderInput);
    // 打印二叉树
    void printTree(Node* tree, double x0, double y0, double x, double y, int n);
};
