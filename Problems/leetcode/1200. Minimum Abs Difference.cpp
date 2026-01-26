class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        int minDiff = INT_MAX;
        int n = arr.size();
        sort(arr.begin(), arr.end()); // O(nlogn)
        for (int i = 1; i < n; i++)   // O(n)
            minDiff = min(minDiff, arr[i] - arr[i - 1]);
        vector<vector<int>> res;
        for (int i = 1; i < n; i++) // O(n)
        {
            if (arr[i] - arr[i - 1] == minDiff)
            {
                res.push_back({arr[i - 1], arr[i]});
            }
        }
        return res;
    }
};