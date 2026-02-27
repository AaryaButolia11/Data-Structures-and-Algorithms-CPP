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
        int M = *max_element(a.begin(), a.end());
        int cnt = count(a.begin(), a.end(), M);
        cout << cnt << "\n";
    }
}

// Best Logic
/*count max no.of dishes in the round

Suppose if M dishes are max then at m-1 only the person with M dishes can finish
if there are 2 persons with M dishes to finish so any among them can finish


So, output is the no.of people with max no.of dishes*/
