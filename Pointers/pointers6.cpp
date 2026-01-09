#include <iostream>
using namespace std;
void update(int *p)
{
    cout << "address stored in p is " << p << endl; // address stored in pointer
    cout << "address of p is " << &p << endl;       // address stored in pointer
    *p = *p + 10;
}
int main()
{
    int arr = 5;
    int *p = &arr;                                  // pointer to the first element of the array
    cout << "address of a is " << &arr << endl;     // address of the variable
    cout << "address stored in p is " << p << endl; // address stored in pointer
    cout << "address of p is " << &p << endl;       // address stored in pointer
    update(p);
    cout << "value of a is " << arr << endl;

    return 0;
}