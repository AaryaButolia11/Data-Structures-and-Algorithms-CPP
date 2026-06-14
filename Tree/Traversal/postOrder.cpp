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
void postOrder(Node *node)
{
    if (node == nullptr)
        return;
    postOrder(nonde->left);
    postOrder(node->right);
    cout << node->data;
}
int main()
{
    return 0;
}