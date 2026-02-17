/*
    Problem: Binary Watch (LeetCode)

    A binary watch has:
    - 4 LEDs for HOURS  (0 to 11)
    - 6 LEDs for MINUTES (0 to 59)

    Given an integer `num`, return all possible times the watch could represent
    such that exactly `num` LEDs are ON.

    ------------------------------------------------------------
    APPROACH:
    ------------------------------------------------------------
    1. A valid time consists of:
         - hour   ∈ [0, 11]
         - minute ∈ [0, 59]

    2. For every possible hour and minute:
         - Count number of 1s in binary representation of hour (4 bits)
         - Count number of 1s in binary representation of minute (6 bits)

    3. If total number of 1s == num:
         → This is a valid time.

    4. Format:
         - Hour: normal integer
         - Minute: must always be 2 digits (e.g., 03, 09)

    ------------------------------------------------------------
    WHY BITSET?
    ------------------------------------------------------------
    std::bitset<N>(value).count()
    → Converts number to binary with N bits
    → count() returns number of set bits (1s)

    Example:
        bitset<4>(5)  = 0101 → count = 2
        bitset<6>(10) = 001010 → count = 2

    ------------------------------------------------------------
    TIME COMPLEXITY:
    ------------------------------------------------------------
    We iterate:
        12 possible hours
        60 possible minutes

    Total iterations = 12 × 60 = 720 (constant)

    Therefore:
        Time Complexity  = O(1)  (since 720 is constant)
        Space Complexity = O(1)  (at most 720 valid times stored)

    ------------------------------------------------------------
*/

class Solution
{
public:
    std::vector<std::string> readBinaryWatch(int num)
    {
        std::vector<std::string> times;

        // Iterate over all possible hours (0 to 11)
        for (int h = 0; h < 12; ++h)
        {

            // Iterate over all possible minutes (0 to 59)
            for (int m = 0; m < 60; ++m)
            {

                // Count number of set bits in hour (4 bits needed)
                int hOnes = std::bitset<4>(h).count();

                // Count number of set bits in minute (6 bits needed)
                int mOnes = std::bitset<6>(m).count();

                // If total LEDs ON equals required num
                if (hOnes + mOnes == num)
                {

                    // Format minute to always have 2 digits
                    std::string time = std::to_string(h) + ":" +
                                       (m < 10 ? "0" : "") +
                                       std::to_string(m);

                    times.push_back(time);
                }
            }
        }

        return times;
    }
};
