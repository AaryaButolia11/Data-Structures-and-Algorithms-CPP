class Solution
{
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>> &grid, int x, int y, int k)
    {
        // 'i' starts from the top row of the submatrix
        int i = x;

        // 'j' starts from the bottom row of the submatrix
        int j = x + k - 1;

        // Continue swapping until we reach the middle
        while (i < j)
        {
            // Iterate through all columns of the submatrix
            for (int z = y; z < y + k; z++)
            {
                // Swap elements in row i and row j (vertical flip)
                swap(grid[i][z], grid[j][z]);
            }

            // Move towards the center
            i++; // next row from top
            j--; // next row from bottom
        }

        // Return modified matrix
        return grid;
    }
};