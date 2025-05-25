

class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        int start = 0, end = n * m - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int row_idx = mid / m;
            int col_idx = mid % m;

            if (mat[row_idx][col_idx] == x) {
                return true;
            } else if (mat[row_idx][col_idx] < x) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return false;
    }
};
