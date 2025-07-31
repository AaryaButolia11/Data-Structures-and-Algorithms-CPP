class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0; // Initialize a variable to store the length of the last word
        int tail = s.length() - 1; // Initialize a pointer to the last character of the string

        // Trim trailing spaces: Move the 'tail' pointer backwards until a non-space character is found or the beginning of the string is reached.
        while (tail >= 0 && s[tail] == ' ') {
            tail--;
        }

        // Count the length of the last word: Move the 'tail' pointer backwards, incrementing 'len' for each non-space character encountered.
        // This loop continues until a space is found or the beginning of the string is reached.
        while (tail >= 0 && s[tail] != ' ') {
            len++; // Increment the length for each character of the word
            tail--; // Move to the previous character
        }

        return len; // Return the calculated length of the last word
    }
};
