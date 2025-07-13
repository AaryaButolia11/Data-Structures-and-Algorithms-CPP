class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // nums.sort(nums.begin,nums.end());
        unordered_set<int> seen_numbers;
        int duplicateNum=-1;
        int n=nums.size();
        for(int num:nums)
        {
            if(seen_numbers.count(num))
            {
                duplicateNum=num;
            }
            else{
                seen_numbers.insert(num);
            }
        }

        long long actualSum=0;
        for(int num:nums)
        {
            actualSum+=num;
        }
        long long expected_Sum=(long long)n*(n+1)/2;
        int missingNum = expected_Sum - (actualSum - duplicateNum);

        return {duplicateNum,missingNum};
    }
};
