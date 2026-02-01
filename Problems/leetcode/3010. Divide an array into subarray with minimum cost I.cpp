class Solution
{
public:
    int minimumCost(vector<int> &nums)
    {
        int cost = nums[0];
        int min1 = INT_MAX, min2 = INT_MAX;

        for (int i = 1; i < nums.size(); i++)
        {
            int curr = nums[i];
            if (curr < min1)
            {
                min2 = min1;
                min1 = curr;
            }
            else if (curr < min2)
            {
                min2 = curr;
            }
        }
        cost += min1;
        cost += min2;
        return cost;
    }
};