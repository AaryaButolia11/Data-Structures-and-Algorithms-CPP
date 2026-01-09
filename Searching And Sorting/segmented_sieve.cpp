#include <iostream>
#include <vector>
#include <cmath>     // For sqrt() function
#include <algorithm> // For max() function
using namespace std;

// Function to implement the Sieve of Eratosthenes up to n
// This is used as a helper to find base primes for the segmented sieve
vector<bool> Sieve(int n)
{
    // Create a sieve array of size n+1, initializing all elements to true
    vector<bool> sieve(n + 1, true);

    // 0 and 1 are not prime numbers
    sieve[0] = sieve[1] = false;

    // Iterate from 2 up to the square root of n
    for (int i = 2; i * i <= n; i++)
    {
        // If i is a prime number
        if (sieve[i])
        {
            // Mark all multiples of i as not prime
            for (int j = i * i; j <= n; j += i)
            {
                sieve[j] = false;
            }
        }
    }
    return sieve;
}

// Function to implement a segmented sieve to find primes in a given range [L, R]
vector<bool> segSieve(int L, int R)
{
    // Find all primes up to sqrt(R) using the basic Sieve
    vector<bool> sieve = Sieve(sqrt(R));
    vector<int> basePrimes;
    for (int i = 0; i < sieve.size(); i++)
    {
        if (sieve[i])
        {
            basePrimes.push_back(i);
        }
    }

    // Create a segmented sieve array for the range [L, R]
    // The size is R - L + 1, and each index 'i' corresponds to the number L + i
    vector<bool> segSieve(R - L + 1, true);

    // Handle the special cases for 0 and 1 if they are in the range
    if (L <= 1 && R >= 1)
    {
        if (L <= 0)
            segSieve[0 - L] = false;
        if (L <= 1)
            segSieve[1 - L] = false;
    }

    // Iterate through the base primes to mark composites in the segmented sieve
    for (auto prime : basePrimes)
    {
        // Find the first multiple of the current prime in the range [L, R]
        long long first_multiple = (static_cast<long long>(L) / prime) * prime;
        if (first_multiple < L)
        {
            first_multiple += prime;
        }

        // Start marking from the first multiple or prime*prime, whichever is greater
        // This is an optimization as smaller multiples would have been marked by smaller primes
        long long j = max(first_multiple, static_cast<long long>(prime) * prime);

        while (j <= R)
        {
            // The number 'j' corresponds to index 'j - L' in the segSieve array
            segSieve[j - L] = false;
            j += prime;
        }
    }

    return segSieve;
}

int main()
{
    // Define the range
    int L = 110, R = 130;

    // Call the segmented sieve function
    vector<bool> segSieveResult = segSieve(L, R);

    // Print the prime numbers found in the range
    cout << "Prime numbers between " << L << " and " << R << " are:" << endl;
    for (int i = 0; i < segSieveResult.size(); i++)
    {
        // If the number at index i is marked as prime (true)
        if (segSieveResult[i])
        {
            cout << i + L << " is prime" << endl;
        }
    }

    return 0;
}
