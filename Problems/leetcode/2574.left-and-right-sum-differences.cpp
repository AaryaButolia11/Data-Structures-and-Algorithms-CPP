/*
 * @lc app=leetcode id=2574 lang=cpp
 *
 * [2574] Left and Right Sum Differences
 *
 * https://leetcode.com/problems/left-and-right-sum-differences/description/
 *
 * algorithms
 * Easy (87.17%)
 * Likes:    1306
 * Dislikes: 117
 * Total Accepted:    248.5K
 * Total Submissions: 281K
 * Testcase Example:  '[10,4,8,3]'
 *
 * You are given a 0-indexed integer array nums of size n.
 *
 * Define two arrays leftSum and rightSum where:
 *
 *
 * leftSum[i] is the sum of elements to the left of the index i in the array
 * nums. If there is no such element, leftSum[i] = 0.
 * rightSum[i] is the sum of elements to the right of the index i in the array
 * nums. If there is no such element, rightSum[i] = 0.
 *
 *
 * Return an integer array answer of size n where answer[i] = |leftSum[i] -
 * rightSum[i]|.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [10,4,8,3]
 * Output: [15,1,11,22]
 * Explanation: The array leftSum is [0,10,14,22] and the array rightSum is
 * [15,11,3,0].
 * The array answer is [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1]
 * Output: [0]
 * Explanation: The array leftSum is [0] and the array rightSum is [0].
 * The array answer is [|0 - 0|] = [0].
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 1000
 * 1 <= nums[i] <= 10^5
 *
 *
 */

// @lc code=start
class Solution
{
public:
    vector<int> leftRightDifference(vector<int> &nums)
    {
        // this denotes curr sum.
        int curr = 0;
        // this is the sum of whole arr
        int sum = accumulate(nums.begin(), nums.end(), 0);
        // store res
        vector<int> res(nums.size());
        // loop in the array
        for (int i = 0; i < nums.size(); ++i)
        {
            // lsum will be curr sum
            int lSum = curr;
            // add curr[i] ele to curr sum
            curr += nums[i];
            // right sum will be total is currSum
            int rSum = sum - curr;
            // update res
            res[i] = abs(rSum - lSum);
        }
        return res;
    }
};
// @lc code=end
