#include <bits/stdc++.h>
using namespace std;
long long value(vector<int> &a)
{
    long long sum = 0;
    int mx = 0;
    for (int x : a)
    {
        mx = max(mx, x);
        sum += mx;
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        long long ans = value(a); // without swap-original value
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(a[i], a[j]);
                ans = max(ans, value(a));
                swap(a[i], a[j]); // revert back
            }
        }
        cout << ans << "\n";
    }
    return 0;
}