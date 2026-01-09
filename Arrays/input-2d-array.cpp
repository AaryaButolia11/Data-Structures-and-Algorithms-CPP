#include <iostream>
using namespace std;

int main()
{
    int brr[3][3];
    int rows = 3;
    int cols = 3;

    cout << "Enter elements column-wise: " << endl;
    for (int i = 0; i < cols; i++) // Loop over columns
    {
        for (int j = 0; j < rows; j++) // Loop over rows
        {
            cin >> brr[j][i]; // Column-wise input
        }
    }

    cout << endl
         << "Matrix printed row-wise: " << endl;
    for (int i = 0; i < rows; i++) // Loop over rows
    {
        for (int j = 0; j < cols; j++) // Loop over columns
        {
            cout << brr[i][j] << " "; // Row-wise output
        }
        cout << endl;
    }

    return 0;
}
