#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        int element = arr[mid];

        if (element == target)
        {
            return mid;
        }
        else if (target < element)
        {
            // search in left
            end = mid - 1;
        }
        else
        {
            // search in right
            start = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;
    cout << "Enter target: ";
    cin >> target;

    int indexofTarget = binarySearch(arr, size, target);
    if (indexofTarget == -1)
    {
        cout << "Not found!" << endl;
    }
    else
    {
        cout << "Target found at index: " << indexofTarget << endl;
    }
    return 0;
}
