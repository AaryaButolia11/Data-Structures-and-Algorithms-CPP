#include <iostream>
using namespace std;

void util(int **p)
{
    **p = **p + 1;
}
int main()
{
    int a = 1  3;
    int *p = &a;
    int **q = &p; // Pointer to pointer to a
    cout << "before" << endl;
    cout << "Value of a: " << a << endl;
    cout << "Value of p: " << p << endl;
    cout << "Value of *p: " << *p << endl;

    util(q);

    cout << "after" << endl;
    cout << "Value of a: " << a << endl;

    return 0;
}