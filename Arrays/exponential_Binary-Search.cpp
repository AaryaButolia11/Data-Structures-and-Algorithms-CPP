#include <iostream>
using namespace std;
// Function to perform binary search
int binarySearch(int arr[], int size, int target)
{
    int min = 0, max = size - 1;
    while (min <= max)
    {
        int mid = min + (max - min) / 2;
        if (arr[mid] == target)
            return mid; // Target found
        else if (arr[mid] < target)
            min = mid + 1; // Search in the right half
        else
            max = mid - 1; // Search in the left half
    }
}

int exponentialSearch(int arr[], int size, int target)
{
    if (arr[0] == target)
        return 0;

    int i = 1;
    while (i < size && arr[i] <= target)
        i *= 2;

    // Call binary search on the found range
    return binarySearch(arr, min(i, size - 1), target);
}
int main()
{
    int a[] = {3, 4, 5, 6, 11, 13, 34, 15, 56, 78, 90, 100};
    int n = sizeof(a) / sizeof(a[0]);
    int x;
    cin >> x;
    int ans = exponentialSearch(a, n, x);
    cout << "Element found at index: " << ans << endl;
    return 0;
}