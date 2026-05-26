class Solution
{
public:
    int numberOfSpecialChars(string word)
    {
        int freq[123] = {0};
        for (char ch : word)
        {
            freq[ch]++;
        }
        int count = 0;
        // ASCII : a : 97 , b = 98 ..... 122 : z
        // ASCII : A : 65,  B = 66 ..... 90  : Z
        for (int i = 97; i <= 122; i++)
        {
            int capIdx = i - 32;
            if (freq[i] > 0 && freq[capIdx] > 0)
                count++;
        }

        return count;
    }
};