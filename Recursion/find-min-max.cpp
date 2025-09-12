#include <iostream>
#include <climits>
// #include <climits.h>
using namespace std;
void findMax(int arr[], int n, int i, int &maxi)
{
    if (i >= n)
    {
        return;
    }
    maxi = max(maxi, arr[i]);
    findMax(arr, n, i + 1, maxi);
}
void findMin(int arr[], int n, int i, int &mini)
{
    if (i >= n)
    {
        return;
    }
    mini = min(mini, arr[i]);
    findMin(arr, n, i + 1, mini);
}
int main()
{
    int arr[] = {3, 5, 1, 8, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxi = INT_MIN;
    int mini = INT_MAX;
    findMax(arr, n, 0, maxi);
    findMin(arr, n, 0, mini);
    cout << "Maximum element is: " << maxi << endl;
    cout << "Minimum element is: " << mini << endl;
    return 0;
}