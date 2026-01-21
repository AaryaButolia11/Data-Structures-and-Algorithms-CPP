#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); // fast I/O
    cin.tie(nullptr);

    int t;
    cin >> t; // number of test cases

    while (t--)
    {
        int n;
        cin >> n; // number of people

        int ans;
        if (n <= 3)
            ans = n; // only one team possible
        else if (n % 2 == 0)
            ans = 0; // can split evenly
        else
            ans = 1; // minimum difference is 1

        cout << ans << '\n'; // output result
    }

    return 0;
}
