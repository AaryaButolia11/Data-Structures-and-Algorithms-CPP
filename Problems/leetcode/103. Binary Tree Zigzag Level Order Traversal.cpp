class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;

        if (root == nullptr)
            return res;

        queue<TreeNode *> q;
        q.push(root);

        bool leftToRight = true;

        while (!q.empty())
        {
            int n = q.size();
            vector<int> row;

            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                row.push_back(node->val);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            if (!leftToRight)
            {
                reverse(row.begin(), row.end());
            }

            res.push_back(row);
            leftToRight = !leftToRight;
        }

        return res;
    }
};