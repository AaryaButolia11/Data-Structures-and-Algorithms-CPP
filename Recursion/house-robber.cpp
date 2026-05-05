using namespace std;
#include <iostream>
#include <vector>
int robHelper(vector<int> &nums, int i)
{
    if (i >= nums.size())
    {
        return 0;
    }
    int rob1 = nums[i] + robHelper(nums, i + 2);
    int rob2 = robHelper(nums, i + 1);
    return max(rob1, rob2);
}
int main()
{
    vector<int> nums = {1, 2, 3, 1};
    cout << robHelper(nums, 0) << endl;
    return 0;
}

// not optimal solution use DP to optimize it
// tc - O(2^N) - exponential time complexity
// sc - O(N) - auxiliary stack space
