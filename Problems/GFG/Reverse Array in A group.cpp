#include <vector>    // For std::vector
#include <algorithm> // For std::min and std::swap

class Solution {
public:
    void reverseInGroups(std::vector<int> &arr, int k) {
        int n = arr.size();

        for (int i = 0; i < n; i += k) {
            int left = i;

            // to handle case when k is not multiple of n
            int right = std::min(i + k - 1, n - 1); // Use std::min

            // reverse the sub-array [left, right]
            while (left < right) {
                std::swap(arr[left++], arr[right--]); // Use std::swap
            }
        }
    }
};
