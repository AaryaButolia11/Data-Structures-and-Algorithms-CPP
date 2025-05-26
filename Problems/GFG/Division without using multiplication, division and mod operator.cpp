class Solution {
  public:
    long long divide(long long dividend, long long divisor) {
        // Edge case: prevent overflow
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long absDividend = abs(dividend);
        long long absDivisor = abs(divisor);

        long long s = 0, e = absDividend, ans = 0;

        while (s <= e) {
            long long mid = s + (e - s) / 2;
            long long product = mid * absDivisor;

            if (product == absDividend) {
                ans = mid;
                break;
            } else if (product < absDividend) {
                ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        if ((dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0))
            return ans;
        else
            return -ans;
    }
};
