class Solution {
public:
    long long maxP = 0;
    long long SUM = 0;
    static constexpr int MOD = 1e9 + 7;

    long long totalSum(TreeNode* root) {
        if (!root) return 0;
        return root->val + totalSum(root->left) + totalSum(root->right);
    }

    long long find(TreeNode* root) {
        if (!root) return 0;

        long long leftSum = find(root->left);
        long long rightSum = find(root->right);

        long long s1 = root->val + leftSum + rightSum;
        long long s2 = SUM - s1;

        maxP = max(maxP, s1 * s2);   
        return s1;
    }

    int maxProduct(TreeNode* root) {
        SUM = totalSum(root);
        find(root);
        return maxP % MOD;
    }
};
