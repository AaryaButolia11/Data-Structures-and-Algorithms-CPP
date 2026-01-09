#include <iostream>
using namespace std;
int main()
{
    int a = 5;
    // creating ref variable
    int &b = a; // b is a reference to a

    cout << a << endl; // Output: 5
    cout << b << endl; // Output: 5

    a++;
    cout << a << endl; // Output: 6
    cout << b << endl; // Output: 6

    b++;
    cout << a << endl; // Output: 7
    cout << b << endl; // Output: 7s

    return 0;
}