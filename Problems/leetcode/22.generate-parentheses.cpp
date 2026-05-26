/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution
{
public:
    void solve(vector<string> &ans, int n, int open, int close, string op)
    {
        // base case
        if (open == 0 && close == 0)
        {
            ans.push_back(op);
            return;
        }

        // include open bracket
        if (open > 0)
        {
            op.push_back('(');
            solve(ans, n, open - 1, close, op);
            // backtrack
            op.pop_back();
        }

        // include close bracket
        if (close > open)
        {
            op.push_back(')');
            solve(ans, n, open, close - 1, op);
            // backtrack
            op.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        int open = n, close = n;
        string op = "";
        solve(ans, n, open, close, op);
        return ans;
    }
};
// @lc code=end
