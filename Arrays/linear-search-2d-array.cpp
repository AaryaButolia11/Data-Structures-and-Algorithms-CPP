#include <iostream>
using namespace std;
bool linearSearch(int arr[3][3], int rows, int cols, int target)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int arr[3][3];
    int rows = 3;
    int cols = 3;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> arr[i][j];
        }
    }
    int target;
    cout << "Enter target: " << endl;
    cin >> target;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    bool present = linearSearch(arr, rows, cols, target);
    if (present == 0)
    {
        cout << target << " is not present ";
    }
    else if (present == 1)
    {
        cout << target << " is present ";
    }

    return 0;
}