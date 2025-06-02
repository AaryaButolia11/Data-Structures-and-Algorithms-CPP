#include <iostream>
using namespace std;
int main()
{
    int rows;
    int columns;
    cout << "Enter no of rows: ";
    cin >> rows;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows - i; j++)
        {
            cout << j + 1;
        }
        cout << endl;
    }
    return 0;
}