#include <iostream>
using namespace std;
int main()
{
    // int arr[] = {2, 4, 6, 9, 12};
    // int brr[5] = {2, 4, 6, 9, 12};
    // int crr[10] = {1, 2, 3, 4, 5}; // rest will take 0

    // error-> too many init..
    // int drr[4] = {1, 2, 3, 4, 5, 6, 7, 8, 9}
    // cout << "Array initialized successfully!" << endl;
    // // cout << arr[0];
    // int arr[] = {1, 3, 5, 7, 9};
    // for (int index = 0; index < 5; index++)
    // {
    //     cout << arr[index] << endl;
    // }

    // int arr[10] = {0}; -> to init. arrray with whole zeros
    int arr[10] = {1, 2, 3};
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}