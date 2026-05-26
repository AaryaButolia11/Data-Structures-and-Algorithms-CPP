#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int i, int j, int row, int col, int arr[4][4], vector<vector<bool>> &visited)
{
    if (i >= 0 && i < row && j >= 0 && j < col && arr[i][j] == 1 && visited[i][j] == false)
    {
        return true;
    }
    return false;
}
void solveMaze(int arr[4][4], int row, int col, int i, int j, vector<vector<bool>> &visited, vector<string> &path, string op)
{
    if (i == row - 1 && j == col - 1)
    {
        path.push_back(op);
        return;
    }

    // down -> i+1,j
    if (isSafe(i + 1, j, row, col, arr, visited))
    {
        visited[i + 1][j] = true;
        solveMaze(arr, row, col, i + 1, j, visited, path, op + "D");
        visited[i + 1][j] = false;
    }
    // left -> i,j-1
    if (isSafe(i, j - 1, row, col, arr, visited))
    {
        visited[i][j - 1] = true;
        solveMaze(arr, row, col, i, j - 1, visited, path, op + "L");
        visited[i][j - 1] = false;
    }
    // right -> i,j+1
    if (isSafe(i, j + 1, row, col, arr, visited))
    {
        visited[i][j + 1] = true;
        solveMaze(arr, row, col, i, j + 1, visited, path, op + "R");
        visited[i][j + 1] = false;
    }
    // up -> i-1,j
    if (isSafe(i - 1, j, row, col, arr, visited))
    {
        visited[i - 1][j] = true;
        solveMaze(arr, row, col, i - 1, j, visited, path, op + "U");
        visited[i - 1][j] = false;
    }
}
int main()
{
    int maze[4][4] = {{1, 0, 0, 0},
                      {1, 1, 0, 1},
                      {1, 1, 0, 0},
                      {1, 1, 0, 1}};

    if (maze[0][0] == 0)
    {
        cout << "No path exists" << endl;
        return 0;
    }

    int row = 4;
    int col = 4;
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    // source value true
    visited[0][0] = true;

    vector<string> path;
    string op = "";

    solveMaze(maze, row, col, 0, 0, visited, path, op);

    cout << "The paths are: " << endl;
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << endl;
    }

    if (path.size() == 0)
    {
        cout << "No path exists" << endl;
    }
    return 0;
}