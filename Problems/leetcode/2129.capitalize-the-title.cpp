/*
 * @lc app=leetcode id=2129 lang=cpp
 *
 * [2129] Capitalize the Title
 */

// @lc code=start
class Solution
{
public:
    string capitalizeTitle(string title)
    {
        //>> is the extraction operator used with stringstream(or cin) in C++.
        // So ss >> word automatically splits the string using spaces.
        stringstream ss(title);
        string word, ans = "";
        while (ss >> word)
        {
            // convert whole word to lower case
            for (char &ch : word)
            {
                ch = tolower(ch);
            }
            // if word length is greater than 2, capitalize first letter
            if (word.size() > 2)
            {
                word[0] = toupper(word[0]);
            }

            ans += word + " ";
        }
        // remove extra trailing space
        ans.pop_back();
        return ans;
    }
};
// @lc code=end
