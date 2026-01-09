#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr{-1, -4, -3, 5, 6, 4, -2, 3, 5, -1};
    int n = arr.size();

    // int low = 0;
    // int mid = 0;

    // while (mid < n)
    // {
    //     if (arr[mid] < 0)
    //     {
    //         swap(arr[low], arr[mid]);
    //         low++;
    //     }
    //     mid++;
    // }

    // for (int x : arr)
    //     cout << x << " ";

    int l = 0;
    int h = n - 1;
    while (l < h)
    {
        if (arr[h] > 0)
        {
            h--;
        }
        else if (arr[l] < 0)
        {
            l++;
        }
        else
        {
            swap(arr[l], arr[h]);
            h--;
            l++;
        }
    }
    for (int x : arr)
        cout << x << " ";

    return 0;
}
