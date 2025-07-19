class Solution {
  public:
    string rearrangeString(string s) {
        // code here
        // Step 1: Count frequency of each character
        int hash[26] = {0}; // Initialize an array to store counts of each letter (a-z)

        for (int i = 0; i < s.size(); i++) {
            hash[s[i] - 'a']++; // Increment count for each character in the string
        }

        // Step 2: Find the character with maximum frequency
        char most_freq_char;
        int max_freq = INT_MIN;
        for(int i = 0; i < 26; i++) {
            if(hash[i] > max_freq) {
                max_freq = hash[i];
                most_freq_char = i + 'a'; // Convert index back to character
            }
        }

        // Step 3: Place the most frequent character in alternate positions (even indices first)
        int index = 0;
        while(max_freq > 0 && index < s.size()) {
            s[index] = most_freq_char;
            max_freq--;
            index += 2; // Move to every other position
        }

        // If we couldn't place all occurrences of the most frequent character, return empty string
        if(max_freq != 0) {
            return "";
        }

        // Step 4: Mark this character as placed by setting its count to 0
        hash[most_freq_char - 'a'] = 0;

        // Step 5: Place the remaining characters in the remaining positions
        for(int i = 0; i < 26; i++) {
            while(hash[i] > 0) {
                // If we've reached the end of string, wrap around to index 1 (odd positions)
                index = index >= s.size() ? 1 : index;
                s[index] = i + 'a'; // Place the current character
                hash[i]--; // Decrement its count
                index += 2; // Move to next alternate position
            }
        }

        return s;
    }
};
