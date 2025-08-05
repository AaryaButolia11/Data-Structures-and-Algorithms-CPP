#include <vector>
#include <cmath>

class Solution {
public:
    // Helper function to find primes up to a given number 'n'
    // This is used by the segmented sieve.
    std::vector<bool> Sieve(int n) {
        std::vector<bool> sieve(n + 1, true);
        sieve[0] = sieve[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (sieve[i]) {
                for (int j = i * i; j <= n; j += i) {
                    sieve[j] = false;
                }
            }
        }
        return sieve;
    }

    // Segmented Sieve to find primes in the range [L, R]
    std::vector<bool> segSieve(int L, int R) {
        // Find all primes up to sqrt(R) using the basic Sieve
        std::vector<bool> sieve = Sieve(static_cast<int>(sqrt(R)));
        std::vector<int> basePrimes;
        for (int i = 0; i < sieve.size(); i++) {
            if (sieve[i]) {
                basePrimes.push_back(i);
            }
        }

        // Create a segmented sieve array for the range [L, R]
        std::vector<bool> segSieve(R - L + 1, true);

        // Handle the special cases for 0 and 1 if they are in the range
        if (L <= 1) {
            if (1 - L >= 0 && 1 - L < segSieve.size()) {
                segSieve[1 - L] = false;
            }
            if (0 - L >= 0 && 0 - L < segSieve.size()) {
                segSieve[0 - L] = false;
            }
        }

        // Iterate through the base primes to mark composites in the segmented sieve
        for (auto prime : basePrimes) {
            // Find the first multiple of the current prime in the range [L, R]
            long long first_multiple = (static_cast<long long>(L) / prime) * prime;
            if (first_multiple < L) {
                first_multiple += prime;
            }

            // Start marking from the first multiple or prime*prime, whichever is greater
            long long j = std::max(first_multiple, static_cast<long long>(prime) * prime);

            while (j <= R) {
                // The number 'j' corresponds to index 'j - L' in the segSieve array
                segSieve[j - L] = false;
                j += prime;
            }
        }

        return segSieve;
    }

    // Corrected function to calculate the product of primes in a range, modulo 10^9 + 7
    int primeProduct(int L, int R) {
        std::vector<bool> segSieveResult = segSieve(L, R);
        long long mul = 1;
        long long M = 1000000007; // Use 10^9 + 7 as the modulus

        for (int i = 0; i < segSieveResult.size(); i++) {
            // If the number is a prime, multiply it into the product
            if (segSieveResult[i]) {
                long long currentNumber = static_cast<long long>(L) + i;
                mul = (mul * currentNumber) % M;
            }
        }
        return static_cast<int>(mul);
    }
};
