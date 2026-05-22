#include <bits/stdc++.h>
using namespace std;

int main()
{
    int X, Y, Z;
    cin >> X >> Y >> Z;
    if (Z <= 50)
        cout << X;
    int diff = Z - 50;
    cout << X + diff * Y;
    return 0;
}
