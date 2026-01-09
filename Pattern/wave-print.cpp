#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void wavePrint(vector<vector<int>> v)
{
    int r = v.size();
    int colcount = v[0].size();
    for (int startCol = 0; startCol < colcount; startCol++)
    {
        if (startCol % 2 == 0)
        {
            for (int i = 0; i < r; i++)
            {
                cout << v[i][startCol] << " ";
            }
        }
        else
        {
            for (int i = r - 1; i >= 0; i--)
            {
                cout << v[i][startCol] << " ";
            }
        }
    }
}
int main()
{
    // Seed for random number generation
    srand(time(0));

    // Creating a 4x4 vector
    vector<vector<int>> matrix(4, vector<int>(4));

    // Fill with random numbers from 1 to 100
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            matrix[i][j] = rand() % 100 + 1;
        }
    }

    wavePrint(matrix);

    return 0;
}
