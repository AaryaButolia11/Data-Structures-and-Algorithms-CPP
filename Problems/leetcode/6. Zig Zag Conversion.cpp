#include <string>
#include <vector>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1)
            return s;

        std::vector<std::string> zigzag(numRows);
        int i = 0; // Index for the input string s
        int row = 0; // Current row in the zigzag pattern
        bool direction = true; // true for top-to-bottom, false for bottom-to-top

        while (i < s.size()) { // Loop while there are characters to process
            if (direction) {
                // Move downwards
                while (row < numRows && i < s.size()) {
                    zigzag[row++].push_back(s[i++]);
                }
                // After reaching the bottom, prepare to move upwards from the second-to-last row
                row = numRows - 2;
            } else {
                // Move upwards
                while (row >= 0 && i < s.size()) {
                    zigzag[row--].push_back(s[i++]);
                }
                // After reaching the top, prepare to move downwards from the second row
                row = 1;
            }
            // Toggle direction for the next segment
            direction = !direction;
        }

        std::string ans = "";
        for (int j = 0; j < zigzag.size(); j++) { // Using j to avoid confusion with i
            ans += zigzag[j];
        }

        return ans;
    }
};
