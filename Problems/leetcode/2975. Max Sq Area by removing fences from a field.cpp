/*
    Problem:
    Given an m x n grid with horizontal and vertical fences,
    remove some fences to form the largest possible square.
    Return the area of the largest square modulo 1e9+7.
    If no square is possible, return -1.

    Approach:
    1. Add boundary fences (1 and m / n) to both horizontal and vertical fences.
    2. Sort all fence positions.
    3. Compute all possible distances between pairs of horizontal fences.
    4. Store these distances in a hash set for fast lookup.
    5. Compute distances between vertical fences and check
       if the same distance exists in horizontal distances.
    6. The maximum common distance gives the largest possible square side.
    7. Return side * side modulo 1e9+7.

    Time Complexity:
    O(H^2 + V^2) where H = horizontal fences, V = vertical fences

    Space Complexity:
    O(H^2) for storing horizontal distances
*/
class Solution
{
public:
    int maximizeSquareArea(int m, int n, vector<int> &hFences, vector<int> &vFences)
    {
        if (m == n)
        {
            long long side = m - 1;
            return (int)((side * side) % 1000000007);
        }

        vector<int> h(hFences.size() + 2), v(vFences.size() + 2);
        h[0] = 1;
        h[h.size() - 1] = m;
        v[0] = 1;
        v[v.size() - 1] = n;

        for (int i = 0; i < hFences.size(); i++)
            h[i + 1] = hFences[i];
        for (int i = 0; i < vFences.size(); i++)
            v[i + 1] = vFences[i];

        sort(h.begin(), h.end());
        sort(v.begin(), v.end());

        unordered_set<int> diffH;
        for (int i = 0; i < h.size(); i++)
        {
            for (int j = i + 1; j < h.size(); j++)
            {
                diffH.insert(h[j] - h[i]);
            }
        }

        int maxSide = -1;
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = i + 1; j < v.size(); j++)
            {
                int d = v[j] - v[i];
                if (diffH.count(d))
                {
                    maxSide = max(maxSide, d);
                }
            }
        }

        if (maxSide == -1)
            return -1;

        long long MOD = 1000000007;
        return (int)((1LL * maxSide * maxSide) % MOD);
    }
};