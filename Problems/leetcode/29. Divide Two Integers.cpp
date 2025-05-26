class Solution {
public:
    int divide(int dividend, int divisor) {
        // Edge case: If dividend is INT_MIN and divisor is -1,
        // the result overflows int range, so return INT_MAX
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Convert both dividend and divisor to long long and take absolute values
        // to safely handle edge cases and avoid overflow
        long long absDividend = abs((long long)dividend);
        long long absDivisor = abs((long long)divisor);

        // Initialize binary search bounds
        long long s = 0, e = absDividend;
        long long ans = 0;

        // Perform binary search to find the largest integer such that:
        // absDivisor * integer <= absDividend
        while (s <= e) {
            long long mid = s + (e - s) / 2;
            long long product = mid * absDivisor;

            if (product == absDividend) {
                // Found exact match, this is our answer
                ans = mid;
                break;
            } else if (product < absDividend) {
                // Mid is a valid candidate, try to find a larger one
                ans = mid;
                s = mid + 1;
            } else {
                // Mid is too large, search left side
                e = mid - 1;
            }
        }

        // Determine the final sign of the result:
        // If dividend and divisor have the same sign, answer is positive
        // Otherwise, answer should be negative
        if ((dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0))
            return ans;
        else
            return -ans;
    }
};
