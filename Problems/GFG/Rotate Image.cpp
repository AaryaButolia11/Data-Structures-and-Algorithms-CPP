Skip to content
Navigation Menu
AaryaButolia11
DSA-CPP

Type / to search
Code
Issues
Pull requests
Actions
Projects
Wiki
Security
Insights
Settings
Files
Go to file
Pattern
Problems
GFG
leetcode
121. Best Time to Buy and Sell Stock.cpp
169. Majority Element.cpp
189. Rotate Array.cpp
2469. Convert the Temperature.cpp
7. Reverse Integer.cpp
temp
temp
README.md
DSA-CPP/Problems/leetcode
/
48. Rotate Image.cpp
in
main

Edit

Preview
Indent mode

Spaces
Indent size

2
Line wrap mode

No wrap
Editing 48. Rotate Image.cpp file contents
Selection deleted
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
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
Use Control + Shift + m to toggle the tab key moving focus. Alternatively, use esc then tab to move to the next interactive element on the page.
New File at Problems/leetcode · AaryaButolia11/DSA-CPP
