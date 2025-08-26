class Solution {
  public:
    int maxProduct(vector<int> &nums) {
        // code here
        int n=nums.size();
        int max_end=nums[0];
        int min_end=nums[0];
        int sum_so_far=nums[0];
        for(int i=1;i<n;i++)
        {
            int temp=max(max(nums[i],nums[i]*max_end),nums[i]*min_end);
            min_end=min(min(nums[i],nums[i]*max_end),nums[i]*min_end);
            max_end=temp;
            sum_so_far=max(sum_so_far,max_end);
        }
        return sum_so_far;
    }
};
