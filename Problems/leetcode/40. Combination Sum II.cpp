class Solution
{
public:
    // logic for unique is to sort them together and then use if condn to find duplicate indices & skip them to neglect duplicasy

    void combSum(vector<int> &candidates, int target, vector<int> v, vector<vector<int>> &ans, int idx)
    {
        // base condn
        if (target == 0)
        {
            ans.push_back(v);
            return;
        }
        if (target < 0)
            return;
        for (int i = idx; i < candidates.size(); i++)
        {
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;
            v.push_back(candidates[i]);
            combSum(candidates, target - candidates[i], v, ans, i + 1);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        combSum(candidates, target, v, ans, 0);
        return ans;
    }
};