class Solution
{
public:
    int alternateDigitSum(int n)
    {
        // convert to string
        string s = to_string(n);
        // to store ans
        int ans = 0;

        // to keep mark of +/- in digit
        int flag = 1;

        // loop
        for (int i = 0; i < s.size(); i++)
        {
            if (flag)
            {
                ans += (s[i] - '0');
            }
            else
            {
                ans -= (s[i] - '0');
            }
            // change flag again
            flag = 1 - flag;
        }
        return ans;
    }
}