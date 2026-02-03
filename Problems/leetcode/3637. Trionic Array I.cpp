// tc-o(n)
// sc-o(1)
class Solution
{
public:
    bool isTrionic(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0;
        // inc
        while (i + 1 < n && nums[i] < nums[i + 1])
        {
            i++;
        }

        // check if still at start or reached end -> false
        if (i == 0 || i == n - 1)
            return false;

        // dec
        while (i + 1 < n && nums[i] > nums[i + 1])
        {
            i++;
        }

        // if reached end -> false
        if (i == n - 1)
            return false;

        // inc
        while (i + 1 < n && nums[i] < nums[i + 1])
        {
            i++;
        }
        // now if at end->return true!
        return (i == n - 1) ? true : false;
    }
};