/*
 * @lc app=leetcode id=2309 lang=cpp
 *
 * [2309] Greatest English Letter in Upper and Lower Case
 */

// @lc code=start
class Solution
{
public:
    string greatestLetter(string s)
    {
        unordered_set<char> lower;
        unordered_set<char> upper;

        // store chars
        for (char ch : s)
        {
            if (islower(ch))
                lower.insert(ch);
            else
                upper.insert(ch);
        }

        // check from greatest to smallest letter
        for (char ch = 'Z'; ch >= 'A'; ch--)
        {
            char small = tolower(ch);
            if (upper.count(ch) && lower.count(small))
                return string(1, ch);
        }

        return "";
    }
};
// @lc code=end
