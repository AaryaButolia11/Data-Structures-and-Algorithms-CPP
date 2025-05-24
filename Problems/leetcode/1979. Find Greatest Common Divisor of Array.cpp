class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int max=nums[nums.size()-1];
        int min=nums[0];
        int ans=1;
        for(int i=2;i<=min;i++)
        {
            if(max%i==0 && min%i==0)
            {
                ans=i;
            }
        }
        return ans;
    }
};
