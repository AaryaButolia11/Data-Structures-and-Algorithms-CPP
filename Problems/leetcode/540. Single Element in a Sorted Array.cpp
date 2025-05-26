class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        int mid = s + (e - s) / 2;
        int ans;

        // Binary Search: Time complexity O(log n)
        // We take advantage of the fact that the array is sorted and 
        // every element appears exactly twice except one.

        while (s <= e) {
            // Base case: only one element left, that is the answer
            if (s == e) {
                ans = nums[mid];
                return ans;
            }

            // Ensure mid is even to check pair properly
            if (mid % 2 == 0) {
                if (nums[mid] == nums[mid + 1]) {
                    // Pair is valid, so the unique element must be on the right
                    s = mid + 2;
                } else {
                    // Mid is the start of a broken pair or is the unique element
                    e = mid;
                }
            } else {
                // mid is odd
                if (nums[mid] == nums[mid - 1]) {
                    // Pair is valid, so the unique element is on the right
                    s = mid + 1;
                } else {
                    // Broken pair, unique element must be on the left
                    e = mid - 1;
                }
            }

            // Recalculate mid
            mid = s + (e - s) / 2;
        }

        // Return in case it's not returned in loop (technically unreachable)
        return ans;
    }
};
