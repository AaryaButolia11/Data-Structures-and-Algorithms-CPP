#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int solve(int n, int x, int y, int z)
{
    // base case
    if (n == 0)
        return 0;

    if (n < 0)
        return INT_MIN;

    int ans1 = solve(n - x, x, y, z);
    int ans2 = solve(n - y, x, y, z);
    int ans3 = solve(n - z, x, y, z);

    int maxi = max(ans1, max(ans2, ans3));
    // if all are invalid
    if (maxi == INT_MIN)
        return INT_MIN;

    return maxi +  1;
}

int main()
{
    int n = 7;
    int x = 5;
    int y = 2;
    int z = 2;

    int ans = solve(n, x, y, z);

    if (ans < 0)
        cout << 0;
    else
        cout << "Answer is: " << ans;

    return 0;
}