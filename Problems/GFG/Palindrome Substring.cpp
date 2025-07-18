class Solution {
public:
    int expandAtIdx(string s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            // Only count if the substring length is >= 2
            if (right - left + 1 >= 2) {
                count++;
            }
            left--;
            right++;
        }
        return count;
    }
    
    int countPS(string &s) {
        int count = 0;
        int n = s.length();
        
        for (int center = 0; center < n; center++) {
            // Odd length palindromes
            count += expandAtIdx(s, center, center);
            // Even length palindromes
            count += expandAtIdx(s, center, center + 1);
        }
        return count;
    }
};
