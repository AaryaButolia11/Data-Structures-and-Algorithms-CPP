class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // solution -1
        // for (int i = 0; i < n; i++) {
        //     nums1[m + i] = nums2[i];
        // }

        // // Sort the merged array
        // sort(nums1.begin(), nums1.end());


        int i = m - 1;            // Last index of initial nums1 elements
        int j = n - 1;            // Last index of nums2
        int k = m + n - 1;        // Last index of nums1's full size

        // Merge in reverse order
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // If any elements left in nums2, copy them
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};
