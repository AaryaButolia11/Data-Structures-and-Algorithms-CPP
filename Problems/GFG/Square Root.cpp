#include <iostream> // For potential debugging, though not strictly needed for the solution

class Solution {
public:
    int floorSqrt(int x) {
        if (x < 0) {
            // Square root of negative numbers is not defined for real numbers.
            // Problem statement says non-negative integer x, so this might not be strictly necessary,
            // but it's good practice for robustness.
            return -1; // Or throw an exception
        }
        if (x == 0 || x == 1) {
            return x; // sqrt(0) = 0, sqrt(1) = 1
        }

        long long s = 0; // Use long long for s and e to avoid overflow when mid*mid is calculated
        long long e = x; // The maximum possible square root is x itself (for x=1, sqrt(1)=1)
                         // For x > 1, the sqrt(x) will be <= x/2 + 1 approximately.
                         // Using x as upper bound is safe and works.
        long long ans = 0; // Store the potential answer (floor of sqrt)

        while (s <= e) {
            long long mid = s + (e - s) / 2;
            long long square = mid * mid; // Calculate square to avoid repeated calculations

            if (square == x) {
                return mid; // Exact square root found
            }
            if (square < x) {
                // mid could be the answer, but we try for a larger one
                ans = mid;
                s = mid + 1;
            } else {
                // mid*mid > x, so the answer must be in the left half
                e = mid - 1;
            }
        }
        return ans; // Return the largest integer whose square is less than or equal to x
    }
};
