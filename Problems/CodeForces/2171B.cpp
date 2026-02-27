#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        if (a[0] == -1 && a[n - 1] == -1)
        {
            for (int i = 0; i < n; i++)
                if (a[i] == -1)
                    a[i] = 0;
            cout << 0 << "\n";
        }
        else if (a[0] == -1)
        {
            a[0] = a[n - 1];
            for (int i = 0; i < n; i++)
                if (a[i] == -1)
                    a[i] = 0;
            cout << 0 << "\n";
        }
        else if (a[n - 1] == -1)
        {
            a[n - 1] = a[0];
            for (int i = 0; i < n; i++)
                if (a[i] == -1)
                    a[i] = 0;
            cout << 0 << "\n";
        }
        else
        {
            for (int i = 0; i < n; i++)
                if (a[i] == -1)
                    a[i] = 0;
            cout << abs(a[n - 1] - a[0]) << "\n";
        }

        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }
}
