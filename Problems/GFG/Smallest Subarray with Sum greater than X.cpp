#include <vector>
#include <algorithm>
#include <limits>

class Solution {
public:
    int smallestSubWithSum(int x, std::vector<int>& arr) {
        int n = arr.size();
        int minLength = std::numeric_limits<int>::max();
        int currentSum = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            currentSum += arr[right];

            while (currentSum > x) {
                minLength = std::min(minLength, right - left + 1);
                currentSum -= arr[left];
                left++;
            }
        }

        return (minLength == std::numeric_limits<int>::max()) ? 0 : minLength;
    }
};
