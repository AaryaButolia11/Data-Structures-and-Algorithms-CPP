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
void inOrder(Node *node)
{
    if (node == nullptr)
        return;
    inOrder(node->left);
    cout << node->data;
    inOrder(node->right);
}
int main()
{
    return 0;
}