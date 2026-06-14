/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        // DFS
        // if(root==NULL) return 0;
        // int maxLeft = maxDepth(root->left);
        // int maxRight = maxDepth(root->right);
        // return max(maxLeft, maxRight)+1;

        // BFS
        if (root == NULL)
            return 0;
        int level = 0;
        vector<vector<int>> ans;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            int s = que.size();
            vector<int> v;
            for (int i = 0; i < s; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                if (node->left != NULL)
                    que.push(node->left);
                if (node->right != NULL)
                    que.push(node->right);
                v.push_back(node->val);
            }
            level++;
            ans.push_back(v);
        }
        return level;
    }
};