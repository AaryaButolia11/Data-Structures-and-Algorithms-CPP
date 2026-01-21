#include <bits/stdc++.h>
using namespace std;

int main()
{
    int X, Y;
    cin >> X >> Y;
    cout << X * (1 << Y) << endl; // 2^Y using bit shift
    return 0;
}
