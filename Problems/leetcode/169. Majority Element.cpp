class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Step 1: Sort the array in ascending order
        sort(nums.begin(), nums.end());

        // Step 2: The majority element must be at the middle index
        // Why? Because it appears more than n/2 times,
        // so it will dominate the center in the sorted array
        return nums[nums.size() / 2];
    }
};
