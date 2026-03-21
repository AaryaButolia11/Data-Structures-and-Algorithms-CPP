#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
void solve(vector<int> &arr, int sum, int &maxi, int i)
{
    // base case
    if (i >= arr.size())
    {
        maxi = max(sum, maxi);
        return;
    }

    // include the current element and skip the next one
    solve(arr, sum + arr[i], maxi, i + 2);
    // exclude the current element and move to the next one
    solve(arr, sum, maxi, i + 1);
}
int main()
{
    vector<int> arr = {1, 2, 4, 9};
    int sum = 0;
    int maxi = INT_MIN;
    int i = 0;
    solve(arr, sum, maxi, i);
    cout << "Maximum sum of non-adjacent elements is: " << maxi;
    return 0;
}