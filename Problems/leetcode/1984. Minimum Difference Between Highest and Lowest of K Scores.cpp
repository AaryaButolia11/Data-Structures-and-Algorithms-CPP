class Solution
{
public:
    int minimumDifference(vector<int> &nums, int k)
    {
        if (k == 1)
            return 0;
        sort(nums.begin(), nums.end());
        int diff = INT_MIN;
        for (int i = 0; i + k - 1 < nums.size(); i++)
        {
            diff = min(diff, nums[i + k - 1] - nums[i]);
        }
        return diff;
    }
};