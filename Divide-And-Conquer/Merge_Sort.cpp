using namespace std;
#include <iostream>
#include <vector>

void merge(vector<int> *arr, int s, int e)
{
    int mid = (s + e) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;
    vector<int> left(len1);
    vector<int> right(len2);

    // int* left=new int[len1];
    int k = s;
    for (int i = 0; i < len1; i++)
    {
        left[i] = (*arr)[k++];
    }
    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        right[i] = (*arr)[k++];
    }

    // merge two sorted arrays
    int leftIdx = 0;
    int rightIdx = 0;
    int mainArrayIdx = s;
    while (leftIdx < len1 && rightIdx < len2)
    {
        if (left[leftIdx] < right[rightIdx])
        {
            (*arr)[mainArrayIdx++] = left[leftIdx++];
        }
        else
        {
            (*arr)[mainArrayIdx++] = right[rightIdx++];
        }
    }

    // copy logic for left array
    while (leftIdx < len1)
    {
        (*arr)[mainArrayIdx++] = left[leftIdx++];
    }
    while (rightIdx < len2)
    {
        (*arr)[mainArrayIdx++] = right[rightIdx++];
    }
}

void mergeSort(vector<int> *arr, int s, int e)
{
    // base case
    // s==e means only one element is present in the array
    // s>e means invalid case
    if (s >= e)
    {
        return;
    }
    // mid of the array
    int mid = (s + e) / 2;
    // left part
    mergeSort(arr, s, mid);
    // right part
    mergeSort(arr, mid + 1, e);

    // now merge both
    merge(arr, s, e);
}
int main()
{
    vector<int> arr = {4, 5, 13, 12, 2};
    int n = arr.size();
    int s = 0;
    int e = n - 1;

    // call merge sort
    mergeSort(&arr, s, e);

    // printing
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}