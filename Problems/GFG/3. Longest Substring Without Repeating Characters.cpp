class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // Stores all unique characters currently present in the window.
        unordered_set<char> st;
        int l = 0, r = 0, maxLen = 0;
        int n = s.size();

        while (r < n)
        {
            if (st.find(s[r]) == st.end())
            {
                // If current character is not in the set add it
                st.insert(s[r]);
                maxLen = max(maxLen, r - l + 1);
                r++;
            }
            else
            {
                // Instead of moving r, shrink the window from the left until the duplicate is removed.

                // Remove the leftmost character:
                st.erase(s[l]);
                l++;
            }
        }
        return maxLen;
    }
};