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
    int solver(TreeNode *root, int &maxi)
    {
        if (root == nullptr)
            return 0;
        int lS = max(0, solver(root->left, maxi));
        int rS = max(0, solver(root->right, maxi));
        maxi = max(maxi, root->val + lS + rS);
        return root->val + max(lS, rS);
    }
    int maxPathSum(TreeNode *root)
    {
        int maxi = INT_MIN;
        solver(root, maxi);
        return maxi;
    }
};