class Solution
{
public:
    int binaryGap(int n)
    {
        int curr = 0;
        int prev = -1;
        int res = 0;
        while (n > 0)
        {
            if ((n & 1) > 0)
            { // n&1 -> to check rightmost bit
                // if it's 1 so that means the right most bit is 1 and we can calculate the distance between the current position and the previous position of 1
                res = (prev != -1) ? max(res, curr - prev) : res;
                prev = curr;
            }
            curr++;
            n >>= 1;
        }
        return res;
    }
};