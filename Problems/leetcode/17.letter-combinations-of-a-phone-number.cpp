/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution
{
    void solve(vector<string> &ans, int index, string op, string digits, vector<string> &mapping)
    {
        // base case
        if (index >= digits.length())
        {
            ans.push_back(op);
            return;
        }

        // 1 case solve, recursive call will solve for rest of the cases
        string val = mapping[digits[index] - '0'];
        for (int i = 0; i < val.length(); i++)
        {
            op.push_back(val[i]);
            solve(ans, index + 1, op, digits, mapping);
            // backtrack
            op.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        int index = 0;
        vector<string> mapping(10);
        mapping[2] = "abc";
        mapping[3] = "def";
        mapping[4] = "ghi";
        mapping[5] = "jkl";
        mapping[6] = "mno";
        mapping[7] = "pqrs";
        mapping[8] = "tuv";
        mapping[9] = "wxyz";

        if (digits.length() == 0)
            return ans;

        string op = "";
        solve(ans, index, op, digits, mapping);
        return ans;
    }
};
// @lc code=end
