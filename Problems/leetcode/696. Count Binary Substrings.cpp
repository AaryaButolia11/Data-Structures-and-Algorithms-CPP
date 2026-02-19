/*
    LeetCode Problem: Count Binary Substrings

    Problem Statement:
    ------------------
    Given a binary string s (containing only '0' and '1'),
    return the number of substrings that:
        1. Have equal number of 0's and 1's
        2. All 0's and all 1's in the substring are grouped consecutively

    Example:
    --------
    Input:  "00110011"
    Output: 6

    Explanation:
    Valid substrings are:
    "0011", "01", "1100", "10", "0011", "01"

    --------------------------------------------------------

    OPTIMIZED APPROACH (O(n) Time | O(1) Space)
    --------------------------------------------
    Instead of generating all substrings (which would be O(n²)),
    we observe an important pattern:

    ✔ Valid substrings only occur between TWO adjacent groups
      of consecutive 0s and 1s.

    Example:
        "00110011"

        Groups:
        00 → length = 2
        11 → length = 2
        00 → length = 2
        11 → length = 2

        From each adjacent pair:
        min(2,2) = 2
        min(2,2) = 2
        min(2,2) = 2

        Total = 6

    Why min(previous_group, current_group)?
    Because the smaller group limits how many balanced substrings
    we can form between them.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countBinarySubstrings(string s)
    {

        // cur = length of current consecutive character group
        int cur = 1;

        // pre = length of previous consecutive character group
        int pre = 0;

        // res = final count of valid substrings
        int res = 0;

        // Start from index 1 (compare with previous character)
        for (int i = 1; i < s.size(); i++)
        {

            // If current character is same as previous
            if (s[i] == s[i - 1])
            {
                cur++; // Increase current group length
            }
            else
            {
                // We found a new group (0 → 1 or 1 → 0)

                // Add minimum of previous and current group
                res += min(cur, pre);

                // Update previous group length
                pre = cur;

                // Reset current group length for new character
                cur = 1;
            }
        }

        // After loop ends, one last comparison remains
        res += min(cur, pre);

        return res;
    }
};

/*
    Time Complexity:  O(n)
        We traverse the string once.

    Space Complexity: O(1)
        Only a few integer variables used.

    --------------------------------------------------------
    KEY INTERVIEW POINT:
    --------------------
    The trick is recognizing we don't need to store all groups.
    Just tracking the current and previous group size is enough.
*/
