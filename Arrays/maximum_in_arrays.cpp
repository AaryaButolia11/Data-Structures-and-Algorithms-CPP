#include <iostream>
#include <limits.h>
using namespace std;
int main()
{
    int max = INT_MIN;
    int arr[] = {1, 4, 6, 7, 8, 2, 3, 4, 4, 5, 67, 88, 9, 3, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    cout << "Maximum is: " << max << endl;

    return 0;
}