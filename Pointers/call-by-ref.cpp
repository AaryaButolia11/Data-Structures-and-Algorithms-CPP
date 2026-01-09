#include <iostream>
using namespace std;
void solve(int &x)
{
    x += 10; // modifies the original variable
}

int main()
{
    int a = 5;
    solve(a);
    cout << a << endl;

    return 0;
}