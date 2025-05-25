class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();       // number of rows
        int m = matrix[0].size();    // number of columns

        // soln1
        // for (int i = 0; i < n; i++) {
        //     if (matrix[i][0] <= target && target <= matrix[i][m - 1]) {
        //         int s = 0, e = m - 1;
        //         while (s <= e) {
        //             int mid = s + (e - s) / 2;
        //             if (matrix[i][mid] == target)
        //                 return true;
        //             else if (matrix[i][mid] < target)
        //                 s = mid + 1;
        //             else
        //                 e = mid - 1;
        //         }
        //         return false;
        //     }
        // }
        // return false;

        // soln2
        int start = 0, end = n * m - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int row_idx = mid / m;
            int col_idx = mid % m;

            if (matrix[row_idx][col_idx] == target) {
                return true;
            } else if (matrix[row_idx][col_idx] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return false; // ✅ placed outside the loop
    }
};
