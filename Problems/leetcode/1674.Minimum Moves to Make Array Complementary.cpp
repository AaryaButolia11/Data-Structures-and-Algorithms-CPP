// Approach: Difference Array Technique
// Time Complexity  : O(n + limit)
// Space Complexity : O(limit)

class Solution
{
public:
    int minMoves(vector<int> &nums, int limit)
    {

        int n = nums.size();

        // Possible sums range from:
        // minimum = 2  (1 + 1)
        // maximum = 2*limit
        //
        // diff[i] stores change in moves at index i
        vector<int> diff(2 * limit + 2, 0);

        // Process every pair
        for (int i = 0; i < n / 2; i++)
        {

            int a = nums[i];
            int b = nums[n - 1 - i];

            /*
                For pair (a,b):

                ----------------------------------------
                Target Sum Range         Moves Required
                ----------------------------------------
                Outside range            2 moves
                [min(a,b)+1,
                 max(a,b)+limit]        1 move
                a+b                      0 moves
                ----------------------------------------
            */

            // Range where 1 move is possible
            int minVal = min(a, b) + 1;

            // Maximum sum achievable in 1 move
            int maxVal = max(a, b) + limit;

            // ---------------------------------------------------
            // Step 1:
            // Assume initially every sum requires 2 moves
            // Add +2 to complete range [2, 2*limit]
            // ---------------------------------------------------

            diff[2] += 2;

            // remove effect after 2*limit
            diff[2 * limit + 1] -= 2;

            // ---------------------------------------------------
            // Step 2:
            // For sums in [minVal, maxVal]
            // only 1 move is needed instead of 2
            //
            // So reduce cost by 1 in this range
            // ---------------------------------------------------

            diff[minVal] += -1;

            // stop reducing after maxVal
            diff[maxVal + 1] -= -1;

            // ---------------------------------------------------
            // Step 3:
            // For exact sum = a+b
            // 0 moves are needed instead of 1
            //
            // So reduce cost by 1 again
            // ---------------------------------------------------

            diff[a + b] += -1;

            // remove effect after a+b
            diff[a + b + 1] -= -1;
        }

        int result = INT_MAX;

        // Prefix sum to compute actual moves
        for (int sum = 2; sum <= 2 * limit; sum++)
        {

            // Build actual cost from difference array
            diff[sum] += diff[sum - 1];

            // Take minimum moves among all target sums
            result = min(result, diff[sum]);
        }

        return result;
    }
};