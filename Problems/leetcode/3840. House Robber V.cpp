class Solution
{
public:
    long long rob(vector<int> &nums, vector<int> &colors)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        vector<long long> dp(n);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            long long skip = dp[i - 1];
            long long take;
            if (colors[i] == colors[i - 1])
            {
                take = nums[i] + (i >= 2 ? dp[i - 2] : 0);
            }
            else
            {
                take = nums[i] + dp[i - 1];
            }
            dp[i] = max(skip, take);
        }
        return dp[n - 1];
    }
};