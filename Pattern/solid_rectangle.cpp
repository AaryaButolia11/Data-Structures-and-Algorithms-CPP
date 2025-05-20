#include <iostream>
using namespace std;
int main()
{
    int rows;
    int columns;
    cout << "Enter no of rows: " << endl;
    cin >> rows;
    cout << "Enter no of columns: " << endl;
    cin >> columns;
    // the outer loop - rows
    for (int i = 0; i < rows; i++)
    { 
        // the inner loop - colms
        for (int j = 0; j < columns; j++)
        {
            cout << ("*");
        }
        cout << endl;
    }
    return 0;
}

// *****
// *****
// *****
// *****
// *****
// *****
// *****
// *****
// *****
// *****
