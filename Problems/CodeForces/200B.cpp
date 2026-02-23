#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    double sum = 0;
    int p;
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        sum += p;
    }
    double res = sum / n;
    cout << res << endl;
    return 0;
}