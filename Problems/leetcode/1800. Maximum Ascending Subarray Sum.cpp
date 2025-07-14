class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        // int i=0;
        int curr=nums[0];
        int maxSum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            curr=nums[i]>nums[i-1]?curr+nums[i]:nums[i];
            maxSum=max(maxSum,curr);
        }
        return maxSum; 
    }
};
