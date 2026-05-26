#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, bool> leftRow;
unordered_map<int, bool> upperDiagonal;
unordered_map<int, bool> lowerDiagonal;

bool isSafe(int row, int col, vector<vector<char>> &board, int n)
{
    if (leftRow[row] || upperDiagonal[n - 1 + col - row] || lowerDiagonal[row + col])
        return false;
    return true;
}

// bool isSafe(int row, int col, vector<vector<char>> &board, int n)
// {
//     int i = row, j = col;

//     // Check left side of current row
//     while (j >= 0)
//     {
//         if (board[row][j] == 'Q')
//             return false;
//         j--;
//     }

//     // Check upper-left diagonal
//     i = row;
//     j = col;
//     while (i >= 0 && j >= 0)
//     {
//         if (board[i][j] == 'Q')
//             return false;
//         i--;
//         j--;
//     }

//     // Check lower-left diagonal
//     i = row;
//     j = col;
//     while (i < n && j >= 0)
//     {
//         if (board[i][j] == 'Q')
//             return false;
//         i++;
//         j--;
//     }

//     return true;
// }

void printSoln(vector<vector<char>> &board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void solve(vector<vector<char>> &board, int col, int n)
{
    // Base case
    if (col >= n)
    {
        printSoln(board, n);
        return;
    }

    // Try placing queen in every row
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 'Q';
            leftRow[row] = true;
            upperDiagonal[n - 1 + col - row] = true;
            lowerDiagonal[row + col] = true;

            // Recursive call
            solve(board, col + 1, n);

            // Backtracking
            board[row][col] = '-';
            leftRow[row] = false;
            upperDiagonal[n - 1 + col - row] = false;
            lowerDiagonal[row + col] = false;
        }
    }
}

int main()
{
    int n = 4;

    vector<vector<char>> board(n, vector<char>(n, '-'));

    solve(board, 0, n);

    return 0;
}