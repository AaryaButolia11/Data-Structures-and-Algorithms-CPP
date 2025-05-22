class Solution {
public:
    // Function to rotate the matrix 90 degrees clockwise in place
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();  // Get the size of the NxN matrix

        // Step 1: Transpose the matrix
        // Transposing means converting rows to columns and vice versa
        // We only iterate for j > i to avoid double swapping
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                // Swap elements across the diagonal
                // matrix[i][j] becomes matrix[j][i] and vice versa
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        // After transposing, reversing each row gives us the 90° clockwise rotated matrix
        for(int i = 0; i < n; ++i) {
            // reverse() is a standard STL function that reverses elements of a container
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

/*
Step 1: Transpose the matrix
---------------------------------
Transposing a matrix means converting rows into columns.
In terms of index: matrix[i][j] becomes matrix[j][i].

We loop only through the upper triangle of the matrix (where j > i),
to avoid double-swapping (which would cancel out the effect).

Step 2: Reverse each row
-----------------------------
After transposing, to achieve a 90-degree clockwise rotation,
we need to reverse the elements of each row.
This mirrors the matrix horizontally, finalizing the rotation.
*/
