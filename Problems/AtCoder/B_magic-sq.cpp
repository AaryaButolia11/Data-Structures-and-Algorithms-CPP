#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N; // Input odd number N

    // Create NxN grid initialized with 0
    vector<vector<int>> grid(N, vector<int>(N, 0));

    // Starting position
    int r = 0;
    int c = N / 2;

    // Place number 1
    grid[r][c] = 1;

    // Fill numbers from 2 to N*N
    for (int k = 2; k <= N * N; k++)
    {
        // Move up-right with modulo
        int new_r = (r - 1 + N) % N;
        int new_c = (c + 1) % N;

        // If empty → place there
        if (grid[new_r][new_c] == 0)
        {
            r = new_r;
            c = new_c;
        }
        else
        {
            // Otherwise move down
            r = (r + 1) % N;
        }

        grid[r][c] = k;
    }

    // Print Magic Square
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}