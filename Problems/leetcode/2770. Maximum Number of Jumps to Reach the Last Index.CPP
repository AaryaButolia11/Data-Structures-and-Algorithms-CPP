// recursive approach

// tc -> O(N2)
// sc -> O(n)

class Solution
{
public:
    int n; // Stores the size of the array

    // Recursive + Memoization function
    // i      -> current index
    // nums   -> given array
    // target -> maximum allowed difference
    // t      -> memoization array
    int solve(int i, vector<int> &nums, int target, vector<int> &t)
    {
        // Base Case:
        // If we reach the last index,
        // no more jumps are needed.
        if (i == n - 1)
        {
            return t[i] = 0;
        }

        // If already computed, return stored answer
        if (t[i] != INT_MIN)
        {
            return t[i];
        }

        // Initialize result with very small value
        // meaning currently no valid path found
        int res = INT_MIN;

        // Try jumping from current index i
        // to every possible next index j
        for (int j = i + 1; j < n; j++)
        {

            // Check if jump condition is satisfied
            // Absolute difference must be <= target
            if (abs(nums[i] - nums[j]) <= target)
            {

                // Make recursive call for next position
                // +1 because we are taking one jump
                int temp = 1 + solve(j, nums, target, t);

                // Store maximum jumps possible
                res = max(res, temp);
            }
        }

        // Store result in memoization array
        // and return it
        return t[i] = res;
    }

    int maximumJumps(vector<int> &nums, int target)
    {

        // Store array size
        n = nums.size();

        // Memoization array
        // INT_MIN means state not computed yet
        vector<int> t(n + 1, INT_MIN);

        // Start recursion from index 0
        int res = solve(0, nums, target, t);

        // If result is negative,
        // destination cannot be reached
        // return -1
        return res < 0 ? -1 : res;
    }
};
