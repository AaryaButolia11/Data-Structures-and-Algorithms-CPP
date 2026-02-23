/*
Problem: Check If a String Contains All Binary Codes of Size K
Platform: LeetCode
Approach: Sliding Window + Hash Set

Idea:
- A binary string of length k has total 2^k possible combinations.
- We slide a window of size k across the string.
- Store each substring in a hash set.
- If number of unique substrings becomes 2^k → return true.
- Otherwise false.

Time Complexity:
O(N * K)
(N substrings, each substring creation takes O(K))

Space Complexity:
O(2^K)
(HashSet stores all possible binary codes)
*/

class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {

        // Hash set to store unique binary substrings
        unordered_set<string> st;

        int n = s.length();

        // Total possible binary codes of length k
        int codes = 1 << k; // 2^k

        // Traverse all substrings of size k
        for (int i = k; i <= n; i++)
        {

            // Extract substring of length k
            string sub = s.substr(i - k, k);

            // Insert only if not present
            if (!st.count(sub))
            {
                st.insert(sub);
                codes--;
            }

            // If all codes found
            if (codes == 0)
            {
                return true;
            }
        }

        // Not all binary codes found
        return false;
    }
};