#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int p[101], ans[101];
    //Read Input
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    //Invert Permutation
    for (int i = 1; i <= n; i++)
    {
        ans[p[i]] = i;
    }
    //Print Result
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}