/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (35.25%)
 * Likes:    13353
 * Dislikes: 468
 * Total Accepted:    1.1M
 * Total Submissions: 2.9M
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', return the length
 * of the longest valid (well-formed) parentheses substring.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()".
 *
 *
 * Example 2:
 *
 *
 * Input: s = ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()".
 *
 *
 * Example 3:
 *
 *
 * Input: s = ""
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= s.length <= 3 * 10^4
 * s[i] is '(', or ')'.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.size();
        stack<int> st;
        if (n == 0)
            return 0;
        int ans = 0;
        st.push(-1);
        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            if (ch == '(')
            {
                st.push(i);
            }
            else
            {
                if (st.empty())
                {
                    st.push(i);
                }
                else
                {
                    st.pop();
                    if (st.empty())
                    {
                        st.push(i);
                    }
                    else
                    {
                        int len = i - st.top();
                        ans = max(ans, len);
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end
