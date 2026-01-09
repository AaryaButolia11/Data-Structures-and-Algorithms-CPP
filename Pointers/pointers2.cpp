#include <iostream>
using namespace std;
int main()
{
    int a = 5;
    // pointer creation
    int *p = &a;               // pointer p is storing the address of a
    cout << sizeof(p) << endl; // size of pointer

    char ch = 'a';
    char *c = &ch;             // pointer to char
    cout << sizeof(c) << endl; // size of pointer to char

    double d = 3.14;
    double *dp = &d;            // pointer to double
    cout << sizeof(dp) << endl; // size of pointer to double
    return 0;
}