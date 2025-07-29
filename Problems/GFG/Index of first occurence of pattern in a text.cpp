// User function Template for C++

class Solution {
  public:
    int findMatching(string text, string pat) {
        // Code here
        int n = text.size();
        int m = pat.size();
        for (int i = 0; i <= n - m; i++) {
            for (int j = 0; j < m; j++) {
                if (pat[j] != text[i + j]) {
                    break;
                }
                if (j == m - 1) {
                    return i;
                }
            }
        }
        return -1;
    }
};
