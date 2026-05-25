#include <iostream>
#include <vector>
using namespace std;

int partition(int arr[], int s, int e)
{
    // step 1: choose pivot element
    int pivotIdx = s;
    int pivotElement = arr[pivotIdx];

    // step 2: find right position of pivot element
    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivotElement)
        {
            count++;
        }
    }

    int rightPivotIdx = s + count;
    swap(arr[pivotIdx], arr[rightPivotIdx]);

    // step 3: place elements on correct side
    int i = s, j = e;

    while (i < rightPivotIdx && j > rightPivotIdx)
    {
        while (arr[i] <= pivotElement)
        {
            i++;
        }

        while (arr[j] > pivotElement)
        {
            j--;
        }

        if (i < rightPivotIdx && j > rightPivotIdx)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return rightPivotIdx;
}

void quickSort(int arr[], int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }

    // partition
    int partitionIndex = partition(arr, s, e);

    // recursive calls
    // left part
    quickSort(arr, s, partitionIndex - 1);

    // right part
    quickSort(arr, partitionIndex + 1, e);
}

int main()
{
    vector<int> arr = {1, 4, 5, 6, 7, 2, 10, 3, 8, 9};

    int n = arr.size();

    int s = 0;
    int e = n - 1;

    quickSort(arr.data(), s, e);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}