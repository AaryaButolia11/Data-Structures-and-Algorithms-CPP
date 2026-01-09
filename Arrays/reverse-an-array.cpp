#include <iostream>
using namespace std;
int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int size = 9;

    int start = 0;
    int end = size - 1;

    while (start <= end)
    {

        swap(arr[start], arr[end]);
        start++;
        end--;
        // if (start > end)
        // {
        //     break;
        // }
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}