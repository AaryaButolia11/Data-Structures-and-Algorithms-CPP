#include <vector>
#include <iostream> // For potential debugging, though not strictly needed for the solution

class Solution {
public:
    int findPivotElem(std::vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;

        while (s <= e) {
            // If the array is not rotated (or only has one element), the first element is effectively the "pivot"
            // or rather, the array is sorted.
            if (s == e) {
                return s;
            }

            int mid = s + (e - s) / 2;

            // Check if mid is the pivot element
            // Condition 1: mid is not the last element AND nums[mid] > nums[mid+1]
            if (mid < e && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            // Condition 2: mid is not the first element AND nums[mid-1] > nums[mid]
            // This means mid-1 is the pivot.
            if (mid > s && nums[mid - 1] > nums[mid]) {
                return mid - 1;
            }

            // If we are in the left sorted part or on the pivot itself,
            // we need to search in the right part.
            // Example: [7,8,1,2,3,4,5,6] -> mid is 2 (value 1). nums[s] (7) > nums[mid] (1).
            // This means the pivot is on the left side of mid. So we search left.
            if (nums[s] <= nums[mid]) { // s to mid is sorted, so pivot must be in mid+1 to e
                s = mid + 1;
            } else { // mid to e is sorted, so pivot must be in s to mid-1
                e = mid - 1;
            }
        }
        return -1; // Should not reach here for a valid rotated sorted array
    }

    int binarySearch(std::vector<int>& arr, int s, int e, int target) {
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (arr[mid] == target) {
                return mid;
            }
            if (arr[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return -1;
    }

    int search(std::vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return -1;
        }
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }

        int pivotIdx = findPivotElem(nums);

        // Case 1: Target is in the first sorted part (from index 0 to pivotIdx)
        if (target >= nums[0] && target <= nums[pivotIdx]) {
            return binarySearch(nums, 0, pivotIdx, target);
        }
        // Case 2: Target is in the second sorted part (from pivotIdx + 1 to end)
        else {
            // Need to handle the case where pivotIdx is the last element (meaning no rotation or pivot is at end)
            // In such a scenario, pivotIdx + 1 would be out of bounds if not careful.
            // However, our findPivotElem will return the index of the largest element.
            // If the array is fully sorted (e.g., [1,2,3,4,5]), findPivotElem will return 4 (index of 5).
            // So the second part search will be from 5 (index 5, which is out of bounds).
            // We need to ensure the search range is valid.
            // If findPivotElem returns the last index, then the target isn't in the second part.
            // This is implicitly handled by the first 'if' block.
            
            // So if target is not in the first half, it must be in the second (if it exists)
            return binarySearch(nums, pivotIdx + 1, n - 1, target);
        }
    }
};
