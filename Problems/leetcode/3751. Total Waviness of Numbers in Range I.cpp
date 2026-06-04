class Solution
{
public:
    int findWNo(int n)
    {
        // convert to string for faster retrieval of left & right elements!
        string s = to_string(n);
        int l = s.length();
        // condition
        if (l < 3)
            return 0;
        int sco = 0;
        // to skip counting the value of 0 we start loop from 1
        // we got till l-2 as we need last ele from 2nd last ele only
        // fr last ele we wont get right value.
        for (int i = 1; i <= l - 2; i++)
        {
            // peak
            if (s[i] > s[i - 1] && s[i] > s[i + 1])
                sco++;

            // valley
            if (s[i] < s[i - 1] && s[i] < s[i + 1])
                sco++;
        }
        return sco;
    }
    int totalWaviness(int num1, int num2)
    {
        int score = 0;
        for (int num = num1; num <= num2; num++)
        { // O(n2-n1)*log10(n)
            score += findWNo(num);
        }
        return score;
    }
};