#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    int countPrimes(int L, int R) {
        if (L > R || R < 2) return 0;

        int limit = sqrt(R);
        std::vector<bool> primeSieve(limit + 1, true);
        primeSieve[0] = primeSieve[1] = false;

        for (int p = 2; p * p <= limit; ++p) {
            if (primeSieve[p]) {
                for (int i = p * p; i <= limit; i += p)
                    primeSieve[i] = false;
            }
        }

        std::vector<int> primes;
        for (int p = 2; p <= limit; ++p) {
            if (primeSieve[p]) {
                primes.push_back(p);
            }
        }

        std::vector<bool> isPrimeSegment(R - L + 1, true);

        for (int p : primes) {
            long long start_val = std::max((long long)p * p, (long long)((L + p - 1) / p) * p);
            for (long long j = start_val; j <= R; j += p) {
                if (j >= L) {
                    isPrimeSegment[j - L] = false;
                }
            }
        }

        if (L <= 1) {
            if (1 >= L && 1 <= R) isPrimeSegment[1 - L] = false;
            if (0 >= L && 0 <= R) isPrimeSegment[0 - L] = false;
        }
        
        int count = 0;
        for (int i = 0; i <= (R - L); ++i) {
            if (isPrimeSegment[i] && (L + i >= 2)) {
                count++;
            }
        }
        return count;
    }
};
