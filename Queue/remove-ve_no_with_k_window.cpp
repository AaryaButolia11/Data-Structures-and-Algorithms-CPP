#include <iostream>
#include <deque>
using namespace std;

void    (int arr[], int n, int k)
{
    deque<int> q;

    // Process first window
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            q.push_back(i);
        }
    }

    // Process remaining windows
    for (int i = k; i < n; i++)
    {
        // Answer for previous window
        if (q.empty())
        {
            cout << 0 << " ";
        }
        else
        {
            cout << arr[q.front()] << " ";
        }

        // Remove out-of-window elements
        while (!q.empty() && (i - q.front() >= k))
        {
            q.pop_front();
        }

        // Insert current element if negative
        if (arr[i] < 0)
        {
            q.push_back(i);
        }
    }

    // Answer for last window
    if (q.empty())
    {
        cout << 0 << " ";
    }
    else
    {
        cout << arr[q.front()] << " ";
    }
}

int main()
{
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int n = 8;
    int k = 3;

    solve(arr, n, k);

    return 0;
}