#include <iostream>
using namespace std;

bool prime_no(int n)
{
    if (n <= 1)
        return false; // ✅ New: Handle edge cases for 0 and 1

    for (int i = 2; i < n; i++) // ✅ Loop stays the same
    {
        if (n % i == 0)
        {
            return false; // ✅ If divisible by any number, not prime
        }
    }

    return true; // ✅ Only return true *after checking all possible divisors*
}

int main()
{
    int n;
    cin >> n;
    bool ans = prime_no(n);
    cout << ans << endl;

    return 0;
}