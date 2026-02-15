#include <iostream>
using namespace std;
int main()
{
    int n;
    int k;
    int count = 0;
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        int sum = 0;
        int temp = i;
        while (temp > 0)
        {
            sum += temp % 10;
            temp /= 10;
        }
        if (sum == k)
        {
            count++;
        }
    }
    cout << count;

    return 0;
}