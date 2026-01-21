#include <bits/stdc++.h>
using namespace std;

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

        // Step 1: sort array and assign colors
        vector<int> sorted_a = a;
        sort(sorted_a.begin(), sorted_a.end());

        // color[i] = 0 (red) or 1 (blue) for value i
        vector<int> color(n + 1); // since 1 ≤ a[i] ≤ n
        for (int i = 0; i < n; i++)
        {
            color[sorted_a[i]] = i % 2; // alternate coloring in sorted order
        }

        // Step 2: check original array adjacency
        bool ok = true;
        for (int i = 0; i < n - 1; i++)
        {
            if (color[a[i]] == color[a[i + 1]])
            {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}
