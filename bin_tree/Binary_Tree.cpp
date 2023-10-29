#include "Binary_Tree.h"

Node* BinaryTree::buildTree(int preStart, int inStart, int inEnd, Node* parent, bool index_LorR)
{//index_LorR是看是左还是右

    if (preStart > preorder.size() - 1 || inStart > inEnd) {
        return NULL;
    }
    Node* root = new Node(preorder[preStart]);
    root->parent = parent;
    if (parent != NULL)
    {
        if (index_LorR == 0)
        {
            parent->left = root;
        }
        if (index_LorR == 1)
        {
            parent->right = root;
        }
    }
    if (index == 0)
    {
        base_root = root;
        index = 1;
    }
    cleardevice();  // 清空窗口
    printTree(base_root, 540, 100, 100, 100, 0);
    Sleep(500);
    int inIndex = search(inorder, inStart, inEnd, root->val);
    root->left = buildTree(preStart + 1, inStart, inIndex - 1, root, 0);
    root->right = buildTree(preStart + inIndex - inStart + 1, inIndex + 1, inEnd, root, 1);

    return root;
}

Node* BinaryTree::buildTree(vector<int>& preorderInput, vector<int>& inorderInput)
{

    this->preorder = preorderInput;
    this->inorder = inorderInput;
    try
    {
        return buildTree(0, 0, inorder.size() - 1, NULL, 0);
    }
    catch (const std::exception&)
    {
        // 弹出一个报错窗口
        //MessageBox(ege::getHWnd(), "这是一个错误信息", "错误", MB_ICONERROR | MB_OK);
        ege::outtextxy(540, 300, "错误");
    }

}

void BinaryTree::printTree(Node* tree, double x0, double y0, double x, double y, int n)
{
    if (tree == NULL)
        return;
    setcolor(EGERGB(0xFF, 0xFF, 0x0));
    setfillcolor(WHITE);
    fillellipse(x0, y0, 20, 20);
    string str = to_string(tree->val); // 将整数转换为字符串
    //char str[2] = { tree->val, '\0' };
    outtextxy(x0 - 5, y0 - 5, str.c_str());
    if (tree->left != NULL) {
        line(x0, y0 + 10, x0 - x / pow(2, n + 1), y0 + y);
        printTree(tree->left, x0 - x / pow(2, n + 1), y0 + y, x, y, n + 1);
    }
    if (tree->right != NULL) {
        line(x0, y0 + 10, x0 + x / pow(2, n + 1), y0 + y);
        printTree(tree->right, x0 + x / pow(2, n + 1), y0 + y, x, y, n + 1);
    }
}
