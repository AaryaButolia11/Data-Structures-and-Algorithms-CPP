class Solution {
public:
    int climbStairs(int n) {
        // Base cases:
        // If n is 1, only one way to climb (1 step)
        // If n is 2, two ways: (1+1) or (2)
        // If n is 3, three ways: (1+1+1), (1+2), (2+1)
        if (n <= 3) return n;

        // Initialize variables for dynamic programming:
        // prev1 = ways to climb (n-1) steps
        // prev2 = ways to climb (n-2) steps
        int prev1 = 3;  // ways to climb 3 steps
        int prev2 = 2;  // ways to climb 2 steps
        int cur = 0;    // current number of ways to climb i steps

        // Start from step 4 up to step n
        for (int i = 3; i < n; i++) {
            cur = prev1 + prev2; // current ways = sum of last two
            prev2 = prev1;       // update prev2 to previous prev1
            prev1 = cur;         // update prev1 to current
        }

        // Return the number of ways to climb n steps
        return cur;        
    }
};
