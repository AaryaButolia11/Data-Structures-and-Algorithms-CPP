class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        
        int top = 0, bottom = rows - 1;
        int left = 0, right = columns - 1;

        vector<int> res;

        while (top <= bottom && left <= right) {
            // Print top row
            for (int i = left; i <= right; ++i) {
                res.push_back(matrix[top][i]);
            }
            top++;

            // Print right column
            for (int i = top; i <= bottom; ++i) {
                res.push_back(matrix[i][right]);
            }
            right--;

            // Print bottom row (if still within bounds)
            if (top <= bottom) {
                for (int i = right; i >= left; --i) {
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // Print left column (if still within bounds)
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return res;
    }
};
