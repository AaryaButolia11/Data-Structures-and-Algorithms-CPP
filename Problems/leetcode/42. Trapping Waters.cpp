class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0; // Handle empty input

        int* leftMax = new int[n];
        int* rightMax = new int[n];
        
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        rightMax[n - 1] = height[n - 1];
        for (int j = n - 2; j >= 0; j--) { // Corrected loop condition from i>=0 to j>=0
            rightMax[j] = max(rightMax[j + 1], height[j]);
        }
        
        int totalW = 0;
        for (int i = 0; i < n; i++) {
            totalW += min(leftMax[i], rightMax[i]) - height[i]; // Corrected calculation
        }

        delete[] leftMax;  // Deallocate memory
        delete[] rightMax; // Deallocate memory

        return totalW;
    }
};
