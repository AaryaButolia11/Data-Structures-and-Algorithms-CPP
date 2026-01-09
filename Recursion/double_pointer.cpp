#include <iostream>
using namespace std;
int main()
{
    int a = 5;
    int *p = &a;  // Pointer to a
    int **q = &p; // Pointer to pointer to a
    cout << &a << endl;
    cout << a << endl;
    cout << p << endl;
    cout << &p << endl;
    cout << *p << endl; // Dereferencing p gives the value of a
    cout << q << endl;
    cout << &q << endl;
    cout << *q << endl;  // Dereferencing q gives the address of p
    cout << **q << endl; // Dereferencing q twice gives the value of a
    return 0;
}