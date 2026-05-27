/*
 * @lc app=leetcode id=3121 lang=cpp
 *
 * [3121] Count the Number of Special Characters II
 */

// @lc code=start
class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        int n = word.length();
        int count = 0;

        vector<int> lastSmall(26, -1);
        vector<int> firstCapital(26, -1);
        for (int i = 0; i < n; i++)
        {
            char ch = word[i];
            if (islower(ch))
            {
                lastSmall[ch - 'a'] = i;
            }
            else
            {
                // capital
                if (firstCapital[ch - 'A'] == -1)
                {
                    firstCapital[ch - 'A'] = i;
                }
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (lastSmall[i] != -1 && firstCapital[i] != -1 && lastSmall[i] < firstCapital[i])
            {
                count++;
            }
        }

        return count;
    }
};
// @lc code=end
