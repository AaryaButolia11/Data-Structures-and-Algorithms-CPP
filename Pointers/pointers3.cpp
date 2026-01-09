#include <iostream>
using namespace std;
int main()
{
    int arr[4] = {12, 14, 16, 18};
    cout << &arr << endl;     // address of the first element
    cout << &arr[0] << endl; // address of the first element using address
    cout << arr[0];
    return 0;
}