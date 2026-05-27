class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int n = word.length();
        int caps = 0;
        for (char ch : word)
        {
            if (isupper(ch))
                caps++;
        }
        // all caps
        if (caps == n)
            return true;
        // all small
        if (caps == 0)
            return true;
        // only 1st check
        if (caps == 1 && isupper(word[0]))
            return true;

        return false;
    }
};