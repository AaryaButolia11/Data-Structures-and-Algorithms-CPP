#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {

        unordered_map<char, int> freq;

        int left = 0;
        int maxFreq = 0; // Highest frequency character in current window
        int maxLen = 0;

        for (int right = 0; right < s.size(); right++)
        {

            // Add current character to window
            freq[s[right]]++;

            // Update maximum frequency
            maxFreq = max(maxFreq, freq[s[right]]);

            // If replacements needed > k, shrink window
            while ((right - left + 1) - maxFreq > k)
            {
                freq[s[left]]--;
                left++;
            }

            // Update answer
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};