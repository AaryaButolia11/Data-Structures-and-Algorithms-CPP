class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2; // Calculate mid to prevent potential overflow

            if (nums[mid] == target) {
                return mid; // Target found, return its index
            } else if (nums[mid] > target) {
                end = mid - 1; // Target is in the left half
            } else { // nums[mid] < target
                start = mid + 1; // Target is in the right half
            }
        }

        // If the loop finishes, the target was not found in the array
        return -1;
    }
};
