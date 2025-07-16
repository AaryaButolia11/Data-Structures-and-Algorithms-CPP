class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int oddCount = 0;  // Initialize count for odd numbers
        int evenCount = 0; // Initialize count for even numbers

        // Iterate through the array to count odd and even numbers
        for (int num : nums) {
            if (num % 2 == 0) {
                evenCount++; // Increment evenCount if the number is even
            } else {
                oddCount++;  // Increment oddCount if the number is odd
            }
        }


        // Check if the array is not empty to avoid out-of-bounds access
        if (!nums.empty()) {
            int parity = nums[0] % 2; // Get the parity of the first element (0 for even, 1 for odd)
                     // Start alternating count with 1 for the first element
        int alternating = 1; // Initialize alternating sequence length

            // Iterate from the second element to find the longest alternating parity sequence
            for (int i = 1; i < nums.size(); i++) {
                int currParity = nums[i] % 2; // Get the parity of the current element
                if (currParity != parity) {   // If current parity is different from the previous
                    alternating++;            // Increment alternating sequence length
                    parity = currParity;      // Update parity to the current element's parity
                }
            }
        }
        
        // Return the maximum of:
        // 1. The total count of even numbers
        // 2. The total count of odd numbers
        // 3. The length of the longest alternating parity subsequence
        return max({evenCount, oddCount, alternating});
    }
};
