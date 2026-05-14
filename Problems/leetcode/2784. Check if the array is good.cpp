class Solution
{
public:
    bool isGood(vector<int> &nums)
    {

        // Sort the array so elements come in order
        sort(nums.begin(), nums.end());

        // Size of array
        int n = nums.size();

        // Check first n-1 elements
        // Expected sequence: 1,2,3,...,n-1
        for (int i = 0; i < n - 1; i++)
        {

            // If element does not match expected value
            // then array is not good
            if (nums[i] != i + 1)
            {
                return false;
            }
        }

        // Last element should also be n-1
        // because maximum element must appear twice
        return nums[n - 1] == n - 1;
    }
};