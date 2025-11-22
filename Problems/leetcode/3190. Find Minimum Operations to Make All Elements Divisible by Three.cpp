class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations=0;
        for(int &nums:nums)
        {
            if(nums%3!=0)
            {
                operations++;
            }
        } 
        return operations;
    }

};
