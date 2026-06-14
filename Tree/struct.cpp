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

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    cout << root->data << endl;        // 1
    cout << root->left->data << endl;  // 2
    cout << root->right->data << endl; // 3

    return 0;
}