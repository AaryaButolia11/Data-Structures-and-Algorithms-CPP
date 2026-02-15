#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int d1 = n / 100;       // hundreds digit
    int d2 = (n / 10) % 10; // tens digit
    int d3 = n % 10;        // units digit

    if (d1 == d2 && d2 == d3)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
