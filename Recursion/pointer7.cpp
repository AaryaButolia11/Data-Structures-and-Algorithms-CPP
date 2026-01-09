#include <iostream>
using namespace std;

void util(int *p)
{
    *p = *p + 1;
}
int main()
{
    int a = 5;
    int *p = &a;
    cout << "before" << endl;
    cout << "Value of a: " << a << endl;
    cout << "Value of p: " << p << endl;
    cout << "Value of *p: " << *p << endl;
    util(p);

    cout << "after" << endl;
    cout << "Value of a: " << a << endl;
    cout << "Value of p: " << p << endl;
    cout << "Value of *p: " << *p << endl;
    return 0;
}