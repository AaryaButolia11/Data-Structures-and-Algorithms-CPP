#include <iostream>
using namespace std;
int main()
{
    // int a = 10;
    // int b = 10;
    // cout << "Address of a: " << &a << endl;
    // cout << "Address of b: " << &b << endl;

    int a = 5;
    // pointer creation
    int *p = &a; // pointer p is storing the address of a
    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    cout << "Value of p: " << p << endl;          // address of a
    cout << "Value at address p: " << *p << endl; // value at address p (dereferencing)
    cout << "Address of p: " << &p << endl;       // address of pointer p
    return 0;
}