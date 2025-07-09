#include <iostream>
using namespace std;

int main()
{
    int rows;
    int columns;
    cout << "Enter no of rows: ";
    cin >> rows;
    cout << "Enter no of columns: ";
    cin >> columns;

    for (int i = 0; i < rows; i++)
    {
        if (i == 0 || i == rows - 1)
        {
            for (int j = 0; j < columns; j++)
            {
                cout << "*";
            }
        }
        else
        {
            cout << "*";
            for (int k = 0; k < columns - 2; k++)
            {
                cout << " ";
            }
            if (columns > 1) // to avoid printing second '*' if columns = 1
                cout << "*";
        }
        cout << endl;
    }

    return 0;
}
