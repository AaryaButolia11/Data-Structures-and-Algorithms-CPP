/*
Problem: Repeated DNA Sequences
Platform: LeetCode 187

Description:
Given a DNA string s consisting of characters 'A', 'C', 'G', and 'T',
return all 10-letter-long substrings that appear more than once.

Approach:
- Use two unordered_sets:
    1. seen → stores substrings seen once
    2. res  → stores repeated substrings
- Slide a window of size 10 across the string.
- If substring already in seen → insert into result.
- Otherwise insert into seen.

Time Complexity:
O(N * 10) ≈ O(N)

Space Complexity:
O(N)
*/

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {

        unordered_set<string> seen; // store visited sequences
        unordered_set<string> res;  // store repeated sequences

        int n = s.length();

        // Traverse all substrings of length 10
        for (int i = 0; i <= n - 10; i++)
        {

            string cur = s.substr(i, 10);

            // If already seen → repeated
            if (seen.count(cur))
            {
                res.insert(cur);
            }

            // Mark as seen
            seen.insert(cur);
        }

        // Convert set to vector
        return vector<string>(res.begin(), res.end());
    }
};