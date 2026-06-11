class Solution
{
public:
    int firstUniqChar(string s)
    {
        vector<int> c(256, 0);

        for (char ch : s)
        {
            c[ch]++;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (c[s[i]] == 1)
            {
                return i;
            }
        }

        return -1;
    }
};