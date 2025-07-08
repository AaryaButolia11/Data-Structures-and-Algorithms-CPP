class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans(size); // Pre-allocate the result vector to the correct size
        int l = 0;
        int r = size - 1;

        // Iterate from the end of the 'ans' array backwards
        for (int i = size - 1; i >= 0; --i) {
            if (abs(nums[l]) > abs(nums[r])) {
                ans[i] = nums[l] * nums[l];
                l++;
            } else {
                ans[i] = nums[r] * nums[r];
                r--;
            }
        }
        return ans;
    }
};
