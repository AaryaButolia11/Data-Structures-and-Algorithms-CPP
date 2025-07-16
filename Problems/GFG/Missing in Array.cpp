#include <vector>
#include <numeric> // Not strictly necessary if you loop manually, but good practice for std::accumulate

class Solution {
public:
    // Change 'missingNum' to 'missingNumber' to match the expected function name
    int missingNum(std::vector<int>& arr) {
        // According to the problem: arr has size n-1, numbers are from 1 to n.
        // So, if arr.size() is 's', then n = s + 1.
        int n = arr.size() + 1;

        // Calculate the expected sum of numbers from 1 to n
        // Use long long for expectedSum to prevent potential overflow for large 'n'.
        long long expectedSum = (long long)n * (n + 1) / 2;

        // Calculate the actual sum of elements present in the array
        long long actualSum = 0;
        for (int num : arr) {
            actualSum += num;
        }

        // The difference is the missing number
        return (int)(expectedSum - actualSum);
    }
};
