class Solution
{
public:
    vector<vector<int>> rotateGrid(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m, n) / 2;

        for (int layer = 0; layer < layers; layer++)
        {

            vector<int> temp;

            int top = layer;
            int bottom = m - layer - 1;
            int left = layer;
            int right = n - layer - 1;

            // ---------------- EXTRACT ----------------

            // top row
            for (int j = left; j <= right; j++)
                temp.push_back(grid[top][j]);

            // right column
            for (int i = top + 1; i <= bottom; i++)
                temp.push_back(grid[i][right]);

            // bottom row
            for (int j = right - 1; j >= left; j--)
                temp.push_back(grid[bottom][j]);

            // left column
            for (int i = bottom - 1; i > top; i--)
                temp.push_back(grid[i][left]);

            // ---------------- ROTATE ----------------

            int sz = temp.size();
            int rotate = k % sz;

            vector<int> rotated(sz);

            for (int i = 0; i < sz; i++)
            {
                rotated[i] = temp[(i + rotate) % sz];
            }

            // ---------------- REFILL ----------------

            int idx = 0;

            // top row
            for (int j = left; j <= right; j++)
                grid[top][j] = rotated[idx++];

            // right column
            for (int i = top + 1; i <= bottom; i++)
                grid[i][right] = rotated[idx++];

            // bottom row
            for (int j = right - 1; j >= left; j--)
                grid[bottom][j] = rotated[idx++];

            // left column
            for (int i = bottom - 1; i > top; i--)
                grid[i][left] = rotated[idx++];
        }

        return grid;
    }
};