#include <vector>
#include <algorithm> // Required for std::max

class Solution
{
public:
    int longestOnes(std::vector<int> &nums, int k)
    {
        int left = 0;      // Left pointer of the sliding window
        int zeroCount = 0; // Counts zeros within the current window [left...right]
        int maxLength = 0; // Stores the maximum length found so far
        int n = nums.size();

        for (int right = 0; right < n; ++right)
        {
            if (nums[right] == 0)
                zeroCount++;

            while (zeroCount > k)
            {
                if (nums[left] == 0)
                {
                    zeroCount--;
                }
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};