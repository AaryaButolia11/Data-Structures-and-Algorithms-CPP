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
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        // Remove duplicates
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());

        int max_len = 1, curr_len = 1;

        for (int i = 1; i < a.size(); i++)
        {
            if (a[i] == a[i - 1] + 1)
            {
                curr_len++;
            }
            else
            {
                curr_len = 1;
            }
            max_len = max(max_len, curr_len);
        }

        cout << max_len << "\n";
    }
    return 0;
}

// Remove duplicates from the vector 'a'
// Step 1: std::unique reorders the vector so that all unique elements
//         are at the beginning. It returns an iterator to the element
//         just past the last unique element.
//         Note: std::unique does NOT actually shrink the vector;
//         elements beyond the new end are left as "garbage".
//
// Step 2: a.erase(...) removes all the leftover duplicate elements
//         after the new end returned by unique, effectively resizing
//         the vector to contain only unique elements.
//
// Important: The vector should be sorted before this operation
//            if you want to remove all duplicates, because unique
//            only removes consecutive duplicates.
// a.erase(unique(a.begin(), a.end()), a.end());
