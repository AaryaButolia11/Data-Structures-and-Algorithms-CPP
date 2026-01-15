class Solution
{
public:
    int maximizeSquareHoleArea(int n, int m, vector<int> &hBars, vector<int> &vBars)
    {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int maxH = 1, cntH = 1;
        int maxV = 1, cntV = 1;

        // Longest consecutive horizontal bars
        for (int i = 1; i < hBars.size(); i++)
        {
            if (hBars[i] == hBars[i - 1] + 1)
                cntH++;
            else
                cntH = 1;

            maxH = max(maxH, cntH);
        }

        // Longest consecutive vertical bars
        for (int i = 1; i < vBars.size(); i++)
        {
            if (vBars[i] == vBars[i - 1] + 1)
                cntV++;
            else
                cntV = 1;

            maxV = max(maxV, cntV);
        }

        int side = min(maxH + 1, maxV + 1);
        return side * side;
    }
};
