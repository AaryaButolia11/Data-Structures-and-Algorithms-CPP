// #include <vector>

// class Solution {
// public:
//     std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums) {
//         std::vector<int> ans;
//         for (int i = 0; i < nums.size(); i++) {
//             int count = 0; // Initialize count to 0 for each element
//             for (int j = 0; j < nums.size(); j++) {
//                 if (nums[i] > nums[j]) {
//                     count++;
//                 }
//             }
//             ans.push_back(count);
//         }
//         return ans;
//     }
// };
#include <vector>
#include <numeric>

class Solution {
public:
    std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums) {
        // Step 1: Initialize counts array
        std::vector<int> counts(101, 0);

        // Step 2: Populate counts with frequencies
        for (int num : nums) {
            counts[num]++;
        }

        // Step 3: Transform counts into prefix sums
        for (int i = 1; i <= 100; ++i) {
            counts[i] += counts[i - 1];
        }

        // Step 4: Generate the result array
        std::vector<int> ans;
        ans.reserve(nums.size());

        for (int num : nums) {
            if (num == 0) {
                ans.push_back(0);
            } else {
                ans.push_back(counts[num - 1]);
            }
        }

        return ans;
    }
};
