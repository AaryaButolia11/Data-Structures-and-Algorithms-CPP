/*
 * @lc app=leetcode id=1655 lang=cpp
 *
 * [1655] Distribute Repeating Integers
 */

// @lc code=start
class Solution
{
public:
    bool canDist(vector<int> &cnts, vector<int> &qty, int ithCust)
    {
        if (ithCust == qty.size())
            return true;

        for (int i = 0; i < cnts.size(); ++i)
        {
            if (cnts[i] >= qty[ithCust])
            {
                cnts[i] -= qty[ithCust];
                if (canDist(cnts, qty, ithCust + 1))
                    return true;
                cnts[i] += qty[ithCust];
            }
        }
        return false;
    }
    bool canDistribute(vector<int> &nums, vector<int> &quantity)
    {
        unordered_map<int, int> Map;
        for (auto n : nums)
        {
            Map[n]++;
        }
        vector<int> cnts;
        for (auto it : Map)
            cnts.push_back(it.second);
        sort(quantity.rbegin(), quantity.rend());
        return canDist(cnts, quantity, 0);
    }
};
// @lc code=end
