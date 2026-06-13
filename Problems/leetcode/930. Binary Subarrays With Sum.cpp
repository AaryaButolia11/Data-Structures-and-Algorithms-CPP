class Solution
{
public:
    int atMost(vector<int> &nums, int goal)
    {
        // base case for req if goal ==0 then another call will br for -1 but that isnt possible as all ele >=0
        if (goal < 0)
            return 0;

        int left = 0;
        int sum = 0;
        int count = 0;
        int n = nums.size();

        for (int right = 0; right < n; right++)
        {
            sum += nums[right];

            // if currsum is greater than goal then reduce size from left side and incr left ptr
            while (sum > goal)
            {
                sum -= nums[left];
                left++;
            }
            // cnt -> total ele
            count += (right - left + 1);
        }
        // return total_cnt
        return count;
    }

    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        // Exactly goal = AtMost(goal) - AtMost(goal - 1)

        // how many lesser than goal minus how many lesser han goal-1
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};