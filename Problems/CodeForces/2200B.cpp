#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;

        bool sorted = true;
        for (int i = 0; i < n - 1; i++)
            if (a[i] > a[i + 1])
            {
                sorted = false;
                break;
            }

        cout << (sorted ? n : 1) << "\n";
    }
}