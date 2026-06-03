/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        int n = s.size();
        for (char c : s)
        {
            // iterate thru input string & check if  any opening brackets recieved just push it in stack
            if (c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            else
            {
                // this condition to check if opening bracket is present in stack or not or else top will give error if stack is empty
                if (st.empty())
                    return false;
                // fetch top value of the stack
                char topEle = st.top();
                // check if the current closing bracket matches the top opening bracket in stack, if it matches pop the top element from stack else return false
                if ((c == ')' && topEle == '(') || (c == '}' && topEle == '{') || (c == ']' && topEle == '['))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        // If stack is empty, all brackets were matched
        return st.empty();
    }
};
// @lc code=end
