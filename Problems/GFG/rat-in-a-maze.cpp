class Solution
{
public:
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, -1, 1, 0};

    char direction[4] = {'D', 'L', 'R', 'U'};

    bool isSafe(int i, int j,
                int row, int col,
                vector<vector<int>> &arr,
                vector<vector<bool>> &visited)
    {
        if (i >= 0 && i < row &&
            j >= 0 && j < col &&
            arr[i][j] == 1 &&
            visited[i][j] == false)
        {
            return true;
        }

        return false;
    }

    void solveMaze(vector<vector<int>> &arr,
                   int row,
                   int col,
                   int i,
                   int j,
                   vector<vector<bool>> &visited,
                   vector<string> &path,
                   string op)
    {
        // Base Case
        if (i == row - 1 && j == col - 1)
        {
            path.push_back(op);
            return;
        }

        for (int k = 0; k < 4; k++)
        {
            int newx = i + dx[k];
            int newy = j + dy[k];

            char dir = direction[k];

            if (isSafe(newx, newy, row, col, arr, visited))
            {
                visited[newx][newy] = true;

                solveMaze(arr,
                          row,
                          col,
                          newx,
                          newy,
                          visited,
                          path,
                          op + dir);

                visited[newx][newy] = false;
            }
        }
    }

    vector<string> ratInMaze(vector<vector<int>> &maze)
    {
        int row = maze.size();
        int col = maze[0].size();

        vector<vector<bool>> visited(
            row,
            vector<bool>(col, false));

        vector<string> path;

        // Source blocked
        if (maze[0][0] == 0)
        {
            return path;
        }

        visited[0][0] = true;

        string op = "";

        solveMaze(maze,
                  row,
                  col,
                  0,
                  0,
                  visited,
                  path,
                  op);

        return path;
    }
};

// Time Complexity: O(4^(n*m))