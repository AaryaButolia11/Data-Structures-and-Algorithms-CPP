class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        int n = A.size();
        vector<int> res(n);
        unordered_map<int, int> mp;
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            mp[A[i]]++;
            if (mp[A[i]] == 2)
                c++;
            mp[B[i]]++;
            if (mp[B[i]] == 2)
                c++;

            res[i] = c;
        }
        return res;
    }
};