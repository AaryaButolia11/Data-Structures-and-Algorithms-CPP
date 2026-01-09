#include <iostream>
#include <vector>
using namespace std;

// Function to implement the Sieve of Eratosthenes
vector<bool> Sieve(int n)
{
    // Create a sieve array of size n+1, initializing all elements to true
    // A value of true means the number is considered a prime candidate
    vector<bool> sieve(n + 1, true);

    // 0 and 1 are not prime numbers, so mark them as false
    sieve[0] = sieve[1] = false;

    // Iterate from 2 up to the square root of n for optimization
    for (int i = 2; i * i <= n; i++)
    {
        // If the current number 'i' is marked as prime
        if (sieve[i])
        {
            // Mark all multiples of 'i' as not prime.
            // We can start marking from i*i because smaller multiples like 2*i, 3*i, etc.,
            // would have already been marked by smaller prime numbers (e.g., 2, 3).
            for (int j = i * i; j <= n; j += i)
            {
                sieve[j] = false;
            }
        }
    }
    return sieve;
}

int main()
{
    // Call the Sieve function to find primes up to 25
    vector<bool> sieve = Sieve(25);

    // Iterate through the sieve and print the prime numbers
    cout << "Prime numbers up to 25 are:" << endl;
    for (int i = 0; i <= 25; i++)
    {
        if (sieve[i])
        {
            cout << i << " is prime" << endl;
        }
    }

    return 0;
}
