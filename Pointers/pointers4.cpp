#include <iostream>
using namespace std;
int main()
{
    int arr[4] = {12, 14, 16, 18};
    cout << &arr << endl;    // address of the first element
    cout << &arr[0] << endl; // address of the first element using address
    cout << arr[0];

    int *p = arr;
    cout << p << endl;  // address of the first element using pointer
    cout << *p << endl; // value of the first element using pointer
    cout << &p << endl;
    return 0;
}