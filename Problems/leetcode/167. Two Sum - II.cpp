class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start=0;
        int end=numbers.size()-1;
        vector<int> ans{-1,-1};
        while(start<=end)
        {
            int sum=numbers[start]+numbers[end];
            if(sum==target)
            {
                ans[0]=start+1;
                ans[1]=end+1;
                return ans;

            }
            else if(sum<target)
            {
                start++;
            }
            else{
                end--;
            }
        }
        return ans;

        
    }
};
