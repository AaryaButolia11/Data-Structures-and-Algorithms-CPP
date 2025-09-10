#include <iostream>
using namespace std;

int fib(int n)
{
    // base condn
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }

    // f(n)=f(n-1)+f(n-2)
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;
    cout << "Enter the term you want to see:";
    cin >> n;
    int ans = fib(n);
    cout << "The " << n << "th term of fibonacci series is: " << ans << endl;
    return 0;
}