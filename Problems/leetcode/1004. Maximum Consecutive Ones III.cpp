#include <vector>
#include <algorithm> // Required for std::max

class Solution {
public:
    int longestOnes(std::vector<int>& nums, int k) {
        int left = 0;           // Left pointer of the sliding window
        int zeroCount = 0;      // Counts zeros within the current window [left...right]
        int maxLength = 0;      // Stores the maximum length found so far
        int n = nums.size();

        // Iterate with the 'right' pointer to expand the window
        for (int right = 0; right < n; ++right) {
            // If the current element is 0, increment zeroCount
            if (nums[right] == 0) {
                zeroCount++;
            }

            // If the number of zeros in the window exceeds 'k',
            // shrink the window from the left until it becomes valid again.
            while (zeroCount > k) {
                // If the element at the 'left' pointer is 0,
                // decrement zeroCount as it's no longer in the window.
                if (nums[left] == 0) {
                    zeroCount--;
                }
                // Move the 'left' pointer to the right to shrink the window.
                left++;
            }

            // At this point, the window [left...right] is valid (contains at most 'k' zeros).
            // Calculate the current window's length and update maxLength if it's greater.
            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
