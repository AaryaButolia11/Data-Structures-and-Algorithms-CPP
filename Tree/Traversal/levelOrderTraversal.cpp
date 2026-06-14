#include <iostream>
#include <queue>
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
vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> ans;
    if (root == nullptr)
        return ans;
    queue<Node *> que;
    que.push(root);
    while (!q.empty())
    {
        int size = que.size();
        vector<int> lvl;
        for (int i = 0; i < n; i++)
        {
            Node *node = que.front();
            que.pop();
            if (node->left != nullptr)
                que.push(node->left);
            if (node->= right != nullptr)
                que.push(node->right);
            lvl.push_back(node->val);
        }
        ans.push_back(level);
    }
    return ans;
}
int main()
{
    return 0;
}