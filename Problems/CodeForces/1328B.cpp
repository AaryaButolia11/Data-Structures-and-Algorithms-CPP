#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;
        long long moves = (b - (a % b)) % b;
        cout << moves << endl;
    }
    return 0;
}