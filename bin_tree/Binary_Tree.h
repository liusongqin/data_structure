#include <vector>
#include<graphics.h>
#include <string>
//#include <windows.h>
using namespace std;


// ����ڵ�ṹ
struct Node {
    int val;  // �ڵ�ֵ
    Node* left, * right, * parent;  // ���ӽڵ㡢���ӽڵ�͸��ڵ�ָ��
    Node(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}  // ���캯��
};



// �����������
class BinaryTree {
private:
    vector<int> preorder, inorder;  // ǰ��������������
    Node* base_root = NULL;
    bool index = 0;
    // �ڸ����ķ�Χ������һ��ֵ�������е�λ��(������)
    int search(vector<int>& vec, int start, int end, int value) {
        for (int i = start; i <= end; i++) {
            if (vec[i] == value) {
                return i;
            }
        }
        return -1;
    }

    // �ݹ�ع���������
    Node* buildTree(int preStart, int inStart, int inEnd, Node* parent, bool index_LorR);

public:
    Node* buildTree(vector<int>& preorderInput, vector<int>& inorderInput);
    // ��ӡ������
    void printTree(Node* tree, double x0, double y0, double x, double y, int n);
};
