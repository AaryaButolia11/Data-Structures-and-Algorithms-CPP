/*
 * @lc app=leetcode id=3300 lang=cpp
 *
 * [3300] Minimum Element After Replacement With Digit Sum
 */

// @lc code=start
class Solution
{
public:
    int digitSum(int n)
    {
        int sum = 0;
        // till digit is greater than 0.
        while (n > 0)
        {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int minElement(vector<int> &nums)
    {
        int minSum = 37;
        // Note that 1 <= nums[i] <= 10^4 and biggest sum can be obtained by 9999 (whose digit sum = 36)
        for (auto &n : nums)
        {
            int sum = digitSum(n);
            // select minimum sum among all the sums obtained by replacing each element with its digit sum.
            minSum = min(minSum, sum);
        }
        return minSum;
    }
};
// @lc code=end
