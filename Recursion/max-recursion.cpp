#include <iostream>
using namespace std;
#include <climits>
void print(int arr[], int n, int i, int max)
{
    // base condn
    if (i == n)
    {
        return;
    }
    if (max < arr[i])
    {
        max = arr[i];
    }
    cout << "current max: " << max << endl;
    print(arr, n, i + 1, max);
}
int main()
{
    int arr[5] = {10, 11, 3, 34, 55};
    int n = 5;
    int i = 0;
    int maxi = INT_MIN;
    print(arr, n, i, maxi);
    return 0;
}