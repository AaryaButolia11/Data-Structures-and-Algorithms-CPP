#include <iostream>

using namespace std;

void transpose(int arr[3][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = i+1 ; j < cols; j++)
        {
            // arr[i][j]=arr[j][i]
            swap(arr[i][j], arr[j][i]);
        }
    }
}

void printArr(int arr[][3], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // arr[i][j]=arr[j][i]
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int arr[3][3];
    int rows = 3;
    int cols = 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "Enter elem: ";
            cin >> arr[i][j];
        }
    }

    printArr(arr, rows, cols);
    transpose(arr, rows, cols);
    printArr(arr, rows, cols);
    return 0;
}