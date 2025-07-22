class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> st; // Stores unique elements in the current window
        int n = nums.size();
        int i = 0; // Left pointer of the sliding window
        int j = 0; // Right pointer of the sliding window
        int sum = 0; // Current sum of elements in the unique subarray
        int result = 0; // Stores the maximum sum found so far

        while (j < n) {
            // If the current element (nums[j]) is not in the set (i.e., it's unique)
            if (!st.count(nums[j])) {
                sum += nums[j]; // Add it to the current sum
                result = max(result, sum); // Update the maximum result
                st.insert(nums[j]); // Add it to the set
                j++; // Move the right pointer forward
            } else {
                // If the current element (nums[j]) is already in the set (i.e., a duplicate)
                // We need to shrink the window from the left until the duplicate is removed
                while (i < n && st.count(nums[j])) { 
                    sum -= nums[i]; // Subtract the element at the left pointer from the sum
                    st.erase(nums[i]); // Remove it from the set
                    i++; // Move the left pointer forward
                }
                // After shrinking, the duplicate `nums[j]` will no longer be in the set `st` (it was not removed in the while loop).
                // It will be handled in the next iteration when `j` is incremented and this `if` condition is re-evaluated.
                // However, the `while` loop condition `st.count(nums[j])` ensures that the loop continues as long as `nums[j]` is present in the set.
                // Once it exits, it means `nums[j]` is no longer in the set, and the outer loop will proceed to add it.
            }
        }
        return result; // Return the maximum sum of a unique subarray
    }
};
