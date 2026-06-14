#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};
void preOrder(Node *node)
{
    if (node == nullptr)
        return;
    cout << node->data;
    preOrder(node->left);
    preOrder(node->right);
}
int main()
{
    return 0;
}