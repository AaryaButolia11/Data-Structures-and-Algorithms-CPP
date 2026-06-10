class Solution
{
public:
    long long maxTotalValue(vector<int> &nums, int k)
    {
        //total ele in array
        int n = nums.size();
        // define max and min ele
        int maxE3691. Maximum Total Subarray Value IIle = INT_MIN;
        int minEle = INT_MAX;

        // find max and min ele from array
        for (int &num : nums)
        {
            maxEle = max(num, maxEle);
            minEle = min(num, minEle);
        }

        // as the max sum will be the difference of maximum ele and minimum ele in array
        // and we can take same subarr again so we multiply the difference by k here to get sum
        
        return k * 1L * (maxEle - minEle);
    }
};