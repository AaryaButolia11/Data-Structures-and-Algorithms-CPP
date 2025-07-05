class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        set<pair<int,int>> ans;
        int i=0;
        int j=1;
        while(j<nums.size())
        {
            int diff=nums[j]-nums[i];
            if(diff==k)
            {
                ans.insert({nums[i],nums[j]});
                ++i;
                ++j;
            }
            else if(diff>k)
            {
                ++i;
            }
            else{
                ++j;
            }
            if(i==j)
            {
                ++j;
            }

        }
        return ans.size();
    }
}

#soln2
#include <vector>
#include <algorithm> // For sort
#include <set>       // For set

class Solution {
public:
    // Helper function for binary search
    // Searches for 'x' in the 'nums' vector starting from 'start_index'
    int binarySearch(const std::vector<int>& nums, int start_index, int x) {
        int low = start_index;
        int high = nums.size() - 1; // Correct end index

        while (low <= high) {
            int mid = low + (high - low) / 2; // Avoid potential overflow

            if (nums[mid] == x) {
                return mid; // Found the element
            } else if (nums[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1; // Element not found
    }

    int findPairs(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        std::set<std::pair<int, int>> ans; // Use a set to store unique pairs

        for (int i = 0; i < nums.size(); ++i) {
            // Optimization: Skip duplicate 'nums[i]' to avoid re-calculating pairs
            // This is crucial for correctness when dealing with k=0 and duplicate numbers
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            // Search for nums[i] + k in the subarray starting from i + 1
            int target = nums[i] + k;
            int found_index = binarySearch(nums, i + 1, target);

            if (found_index != -1) {
                // If found, insert the pair into the set
                ans.insert({nums[i], nums[found_index]});
            }
        }
        return ans.size();
    }
};
