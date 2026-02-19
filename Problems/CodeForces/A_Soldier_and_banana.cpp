#include <iostream>
using namespace std;

int main()
{
    /*
        k -> cost of first banana
        n -> initial money soldier has
        w -> number of bananas to buy
    */
    long long k, n, w;
    cin >> k >> n >> w;

    /*
        Total cost of bananas:
        k + 2k + 3k + ... + wk

        = k * (1 + 2 + 3 + ... + w)

        Using formula:
        1 + 2 + ... + w = w * (w + 1) / 2

        So,
        total_cost = k * w * (w + 1) / 2
    */
    long long total_cost = k * w * (w + 1) / 2;

    /*
        If total_cost > n:
            Borrow = total_cost - n
        Else:
            Borrow = 0

        max(0LL, total_cost - n) ensures
        we never print a negative value.
    */
    long long amount_to_borrow = max(0LL, total_cost - n);

    // Output the final answer
    cout << amount_to_borrow << endl;

    return 0;
}
