#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

vector<vector<int>> preInPostTraversal(TreeNode *root)
{
    vector<int> pre, in, post;

    if (root == nullptr)
        return {pre, in, post};

    stack<pair<TreeNode *, int>> st;
    st.push({root, 1});

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        // Preorder
        if (it.second == 1)
        {
            pre.push_back(it.first->val);

            it.second++;
            st.push(it);

            if (it.first->left != nullptr)
            {
                st.push({it.first->left, 1});
            }
        }

        // Inorder
        else if (it.second == 2)
        {
            in.push_back(it.first->val);

            it.second++;
            st.push(it);

            if (it.first->right != nullptr)
            {
                st.push({it.first->right, 1});
            }
        }

        // Postorder
        else
        {
            post.push_back(it.first->val);
        }
    }

    return {pre, in, post};
}

int main()
{

    /*
             1
           /   \
          2     3
         / \   / \
        4  5  6   7
    */

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<vector<int>> ans = preInPostTraversal(root);

    cout << "Preorder: ";
    for (int x : ans[0])
        cout << x << " ";

    cout << "\nInorder: ";
    for (int x : ans[1])
        cout << x << " ";

    cout << "\nPostorder: ";
    for (int x : ans[2])
        cout << x << " ";

    cout << endl;

    return 0;
}