#include <iostream>
using namespace std;
int main()
{
    int arr[50];
    int n;
    cout << "How many no you want to input? :" << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter no: " << i + 1 << " : ";
        cin >> arr[i];
    }
    cout << "Doubles : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << 2 * arr[i] << " ";
    }
    return 0;
}
