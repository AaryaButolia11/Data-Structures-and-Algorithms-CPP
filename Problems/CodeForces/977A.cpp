#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k; // Input total number of soldiers and jump step
    for (int i = 0; i < k; i++)
    {
        if (n % 10 == 0)
            n /= 10;
        else
            n -= 1;
    }
    cout << n << endl; // Output the remaining number of soldiers
    return 0;
    // return 0;
}