class Solution
{
public:
    unordered_map<int, bool> leftRow;
    unordered_map<int, bool> upperDiagonal;
    unordered_map<int, bool> lowerDiagonal;
    int count = 0;

    bool isSafe(int row, int col, vector<vector<char>> &board, int n)
    {
        if (leftRow[row] ||
            upperDiagonal[n - 1 + col - row] ||
            lowerDiagonal[row + col])
            return false;

        return true;
    }

    void appendSoln(vector<vector<char>> &board,
                    int n,
                    vector<vector<string>> &ans)
    {
        vector<string> temp;

        for (int i = 0; i < n; i++)
        {
            string op = "";

            for (int j = 0; j < n; j++)
            {
                op.push_back(board[i][j]);
            }

            temp.push_back(op);
        }

        ans.push_back(temp);
        count++;
    }

    void solve(vector<vector<char>> &board,
               int col,
               int n,
               vector<vector<string>> &ans)
    {
        if (col >= n)
        {
            appendSoln(board, n, ans);
            return;
        }

        for (int r = 0; r < n; r++)
        {
            if (isSafe(r, col, board, n))
            {
                board[r][col] = 'Q';

                leftRow[r] = true;
                upperDiagonal[n - 1 + col - r] = true;
                lowerDiagonal[r + col] = true;

                solve(board, col + 1, n, ans);

                board[r][col] = '.';

                leftRow[r] = false;
                upperDiagonal[n - 1 + col - r] = false;
                lowerDiagonal[r + col] = false;
            }
        }
    }

    int totalNQueens(int n)
    {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> ans;

        solve(board, 0, n, ans);

        return count;
    }
};