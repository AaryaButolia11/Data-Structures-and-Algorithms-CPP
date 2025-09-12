#include <iostream>

using namespace std;

int climbStairs(int n)
{
    // base condition
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    // f(n)=f(n-1)+f(n-2)
    int ans = climbStairs(n - 1) + climbStairs(n - 2);
    return ans;
}

int main()
{
    int n;
    cout << "Enter the number of stairs:";
    cin >> n;

    int ans = climbStairs(n);
    cout << "ans is: " << ans << endl;
    return 0;
}