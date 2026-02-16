/*
    🔁 Reverse Bits (32-bit Integer)

    🧠 Problem:
    Given a 32-bit integer n, reverse its binary bits
    and return the resulting integer.

    💡 Approach:
    We reverse bits using bit manipulation.

    Steps:
    1. Extract the last bit of n using (n & 1)
    2. Shift result left to make space
    3. Add extracted bit to result using OR
    4. Shift n right to process next bit
    5. Repeat 32 times (since integer has 32 bits)

    ⏱ Time Complexity: O(1)
    - Loop runs exactly 32 times.

    📦 Space Complexity: O(1)
    - Only one extra variable used.

    🔑 Concepts Used:
    - Bitwise AND (&)
    - Bitwise OR (|)
    - Left Shift (<<)
    - Right Shift (>>)
*/

class Solution
{
public:
    int reverseBits(int n)
    {

        // If number is 0, reversed will also be 0
        if (n == 0)
            return 0;

        int res = 0; // This will store the reversed number

        // Loop exactly 32 times (since int has 32 bits)
        for (int i = 0; i < 32; i++)
        {

            // Shift result left to make space for next bit
            res <<= 1;

            // Extract last bit of n and add it to result
            // (n & 1) gives last bit (0 or 1)
            res |= (n & 1);

            // Shift n right to process next bit
            n >>= 1;
        }

        // Return reversed bits
        return res;
    }
};
