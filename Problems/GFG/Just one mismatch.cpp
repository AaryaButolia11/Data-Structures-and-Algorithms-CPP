class Solution {
public:
    string isStringExist(vector<string> arr, int N, string S) {
        // N is redundant here as arr.size() can be used
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i].length() == S.length()) {
                int count = 0;
                for (int j = 0; j < arr[i].length(); j++) {
                    if (arr[i][j] != S[j]) {
                        count++;
                    }
                    if (count > 1) { // Optimization: if more than 1 difference, no need to check further
                        break;
                    }
                }
                // If exactly one difference found, return "True"
                if (count == 1) {
                    return "True";
                }
            }
        }
        // If no such string is found after checking all strings, return "False"
        return "False";
    }
};
