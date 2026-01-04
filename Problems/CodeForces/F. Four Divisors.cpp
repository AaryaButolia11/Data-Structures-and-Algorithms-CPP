#include <iostream>
using namespace std;
int D(int num)
{
    int count = 0; // this is the int variable to count the number of divisors
    for (int fact = 1; fact * fact <= num; fact++)
    {
        if (num % fact == 0)
        {
            count++; // count the divisor
            if (fact * fact != num)
                count++; // count the complementary divisor
        }
    }
    return count;
}
int main()
{
    int n;
    int res = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (D(i) == 4)
        {
            res++;
        }
    }
    cout << res;
    return 0;
}
