#include <iostream>
#include <cmath>
using namespace std;

int dtob(int n)
{
    int binaryno = 0;
    int i = 0;
    while (n > 0)
    {
        int bit = n % 2;

        binaryno = bit * pow(10, i++) + binaryno;
        n = n / 2;
    }
    return binaryno;
}
int main()
{
    int n;
    cin >> n;
    int binary = dtob(n);
    cout << binary << endl;

    return 0;
}