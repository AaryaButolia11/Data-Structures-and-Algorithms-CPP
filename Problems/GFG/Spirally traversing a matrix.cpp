class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        vector<int> res;
        int rows = mat.size();
        int cols = mat[0].size();
        
        int top = 0, bottom = rows - 1;
        int left = 0, right = cols - 1;
        
        while (top <= bottom && left <= right) {
            // Traverse top row
            for (int i = left; i <= right; ++i) {
                res.push_back(mat[top][i]);
            }
            top++;
            
            // Traverse right column
            for (int i = top; i <= bottom; ++i) {
                res.push_back(mat[i][right]);
            }
            right--;
            
            // Traverse bottom row if within bounds
            if (top <= bottom) {
                for (int i = right; i >= left; --i) {
                    res.push_back(mat[bottom][i]);
                }
                bottom--;
            }
            
            // Traverse left column if within bounds
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    res.push_back(mat[i][left]);
                }
                left++;
            }
        }
        
        return res;
    }
};
