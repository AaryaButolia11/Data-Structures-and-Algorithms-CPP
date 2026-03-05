class Solution
{
public:
    int minOperations(string s)
    {
        int count1 = 0, count2 = 0;

        for (int i = 0; i < s.length(); i++)
        {

            // pattern 0101...
            if (i % 2 == 0)
            {
                if (s[i] != '0')
                    count1++;
            }
            else
            {
                if (s[i] != '1')
                    count1++;
            }

            // pattern 1010...
            if (i % 2 == 0)
            {
                if (s[i] != '1')
                    count2++;
            }
            else
            {
                if (s[i] != '0')
                    count2++;
            }
        }

        return min(count1, count2);
    }
};