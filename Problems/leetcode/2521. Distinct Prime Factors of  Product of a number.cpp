#include <vector>
#include <set>
#include <cmath>

class Solution {
public:
    int distinctPrimeFactors(std::vector<int>& nums) {
        std::set<int> primeFactors;

        for (int n : nums) {
            // Check for divisibility by 2
            if (n % 2 == 0) {
                primeFactors.insert(2);
                while (n % 2 == 0) {
                    n /= 2;
                }
            }

            // Check for divisibility by odd numbers starting from 3
            for (int i = 3; i * i <= n; i += 2) {
                if (n % i == 0) {
                    primeFactors.insert(i);
                    while (n % i == 0) {
                        n /= i;
                    }
                }
            }

            // If n is still greater than 2, it's a prime factor itself
            if (n > 2) {
                primeFactors.insert(n);
            }
        }
        return primeFactors.size();
    }
};
