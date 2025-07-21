#include <string> // Don't forget to include the string header

class Solution {
public:
    std::string makeFancyString(std::string s) {
        std::string ans; // This will store our fancy string

        for (int i = 0; i < s.size(); ++i) {
            ans.push_back(s[i]); // Always add the current character first

            // Check if we have at least 3 characters AND if the last three are identical
            if (ans.size() >= 3 &&
                ans[ans.size() - 1] == ans[ans.size() - 2] &&
                ans[ans.size() - 2] == ans[ans.size() - 3]) {
                ans.pop_back(); // If they are, remove the character we just added
            }
        }
        return ans; // Return the final fancy string
    }
};
