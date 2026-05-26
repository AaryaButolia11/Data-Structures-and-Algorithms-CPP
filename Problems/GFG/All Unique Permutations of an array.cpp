// All Unique Permutations of an array
// Given an array arr[] that may contain duplicates. Find all possible distinct permutations of the array in sorted order.
// Note: A sequence A is greater than sequence B if there is an index i for which Aj = Bj for all j<i and Ai > Bi.

class Solution
{
public:
    vector<vector<int>> ans;
    void solve(vector<int> &arr, int index)
    {
        // Base Case
        if (index >= arr.size())
        {
            ans.push_back(arr);
            return;
        }
        unordered_set<int> used;
        for (int j = index; j < arr.size(); j++)
        {
            // Skip duplicates at current recursion level
            if (used.count(arr[j]))
                continue;
            used.insert(arr[j]);
            swap(arr[index], arr[j]);
            solve(arr, index + 1);
            // Backtracking
            swap(arr[index], arr[j]);
        }
    }

    vector<vector<int>> uniquePerms(vector<int> &arr)
    {
        // Sort the array to ensure duplicates are adjacent, which helps in skipping them easily
        sort(arr.begin(), arr.end());

        solve(arr, 0);
        // Sort the result to ensure the output is in sorted order
        sort(ans.begin(), ans.end());

        return ans;
    }
};