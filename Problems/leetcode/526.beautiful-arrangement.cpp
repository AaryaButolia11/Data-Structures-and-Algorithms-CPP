/*
 * @lc app=leetcode id=526 lang=cpp
 *
 * [526] Beautiful Arrangement
 */

// @lc code=start
class Solution
{
public:
    void cntArr(int n, vector<int> &v, int &ans, int idx)
    {
        if (idx == n + 1)
        {
            ++ans;
            return;
        }
        for (int i = 1; i <= n; ++i)
        {
            if (v[i] == 0 && (idx % i == 0 || i % idx == 0))
            {
                v[i] = idx;
                cntArr(n, v, ans, idx + 1);
                v[i] = 0; // backtrack
            }
        }
    }
    int countArrangement(int n)
    {
        vector<int> v(n + 1, 0);
        int ans = 0;
        cntArr(n, v, ans, 1);
        return ans;
    }
};
// @lc code=end
