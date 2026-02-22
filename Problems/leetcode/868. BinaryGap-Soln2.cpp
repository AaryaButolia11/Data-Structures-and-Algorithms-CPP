class Solution
{
public:
    int binaryGap(int n)
    {
        int prev = -1;
        int res = 0;
        for (int curr = 0; curr < 32; curr++)
        {
            if (((n >> curr) & 1) > 0)
            { // n>>curr gives currth bit in n and &1 gives 1 if curr bit is already 1
                res = (prev != -1) ? max(res, curr - prev) : res;
                prev = curr;
            }
        }

        return res;
    }
};