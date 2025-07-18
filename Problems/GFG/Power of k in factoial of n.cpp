#include <algorithm> // Required for std::min
#include <cmath>     // Required for std::sqrt
#include <limits>    // Required for std::numeric_limits

class Solution {
public:
    // Helper function to count the exponent of a prime p in n!
    int countPrimeInFactorial(int n, int p) {
        int count = 0;
        while (n > 0) {
            n /= p; // Integer division
            count += n;
        }
        return count;
    }

    int maxKPower(int n, int k) {
        if (k == 1) {
            // As per common interpretations, if k=1, any power of 1 divides n!
            // assuming n! is defined (n >= 0). This usually implies an
            // infinitely large 'x'. Returning a very large number or
            // specific indicator is common. For competitive programming,
            // 'inf' might not be allowed as return type.
            // Given the problem context of finding a *highest value*,
            // and the example outputs being finite, it implies k > 1.
            // If 1 is explicitly allowed and needs a finite answer,
            // the problem statement needs clarification.
            // For now, consistent with common interpretation for this type of problem.
            return std::numeric_limits<int>::max(); 
        }

        if (n < 0) {
            // Or throw an exception, depending on problem constraints
            return 0; // Or handle error
        }
        if (k <= 0) {
            // Or throw an exception
            return 0; // Or handle error
        }

        int ans = std::numeric_limits<int>::max(); // Initialize with a very large number
        int temp_k = k;

        // Find prime factors of k and their exponents
        for (int p = 2; p * p <= temp_k; ++p) {
            if (temp_k % p == 0) {
                int k_power_in_k = 0;
                while (temp_k % p == 0) {
                    k_power_in_k++;
                    temp_k /= p;
                }
                
                int n_power_in_factorial = countPrimeInFactorial(n, p);
                
                // If a prime factor of k is not present in n!, then x must be 0
                if (n_power_in_factorial == 0) {
                    return 0;
                }
                
                ans = std::min(ans, n_power_in_factorial / k_power_in_k);
            }
        }
        
        // If temp_k is still greater than 1, it means temp_k itself is a prime factor
        if (temp_k > 1) {
            int k_power_in_k = 1; // Its exponent in k is 1
            int n_power_in_factorial = countPrimeInFactorial(n, temp_k);
            
            if (n_power_in_factorial == 0) {
                return 0;
            }
                
            ans = std::min(ans, n_power_in_factorial / k_power_in_k);
        }
        
        return ans;
    }
};
