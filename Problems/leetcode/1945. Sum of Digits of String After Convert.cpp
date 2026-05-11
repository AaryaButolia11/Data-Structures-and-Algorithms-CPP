class Solution
{
public:
    int getLucky(string s, int k)
    {
        string numStr = "";
        for (int i = 0; i < s.length(); i++)
        {
            numStr += to_string(s[i] - 'a' + 1);
        }
        while (k--)
        {
            int sum = 0;
            for (int i = 0; i < numStr.length(); i++)
            {
                sum += stoi(string(1, numStr[i]));
                // string(1,numStr[i])->Creates a string of length 1.
            }

            numStr = to_string(sum);
        }
        return stoi(numStr);
    }
};