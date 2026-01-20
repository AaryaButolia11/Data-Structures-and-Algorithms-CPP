class Solution
{
public:
    vector<int> minBitwiseArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            int x = nums[i];
            if (x == 2)
                ans[i] = -1;
            else
            {
                int mask = ~(((x + 1) & ~x) >> 1);
                ans[i] = x & mask;
            }
        }
        return ans;
    }
};