#include <vector>
// No need for <iostream> unless for debugging purposes

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

    int search(std::vector<int>& arr, int key) {
        int n = arr.size();

        // Handle edge cases for empty or single-element arrays
        if (n == 0) {
            return -1;
        }
        if (n == 1) {
            return arr[0] == key ? 0 : -1;
        }

        // Find the pivot element's index
        int pivotIdx = findPivotElem(arr);

        // Determine which sorted half the key might be in
        // If the key is greater than or equal to the first element and less than or equal to the pivot element
        // (which is the largest element in the first sorted half),
        // then search in the first half (from index 0 to pivotIdx).
        if (key >= arr[0] && key <= arr[pivotIdx]) {
            return binarySearch(arr, 0, pivotIdx, key);
        }
        // Otherwise, the key must be in the second sorted half (from pivotIdx + 1 to the end of the array).
        else {
            return binarySearch(arr, pivotIdx + 1, n - 1, key);
        }
    }
};
