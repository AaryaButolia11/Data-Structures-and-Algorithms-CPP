// User function template for C++
class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        int row = 0;
        int col = mat[0].size() - 1;

        while (row < mat.size() && col >= 0) {
            if (mat[row][col] == x) {
                return true;
            }
            else if (mat[row][col] < x) {
                row++; // Move down
            }
            else {
                col--; // Move left
            }
        }

        return false;

    }
};
