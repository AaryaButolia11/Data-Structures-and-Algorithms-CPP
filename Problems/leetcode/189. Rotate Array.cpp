class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();          // Get the size of the array
        k %= n;                       // If k > n, rotate only k % n steps

        // Step 1: Reverse the entire array
        // This moves the last k elements to the front, but in reverse order
        reverse(nums.begin(), nums.end());  

        // Step 2: Reverse the first k elements (which were originally the last k)
        // This puts them back in their original order at the start of the array
        reverse(nums.begin(), nums.begin() + k);  

        // Step 3: Reverse the remaining n-k elements
        // This puts the rest of the array (originally first n-k elements) back in order
        reverse(nums.begin() + k, nums.end());  

        // No need to return anything since the vector is modified in-place
    }
};
