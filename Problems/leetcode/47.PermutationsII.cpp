class Solution
{
public:
    vector<vector<int>> res;

    void perm(vector<int> &nums, int i)
    {

        // Base Case
        if (i >= nums.size())
        {
            res.push_back(nums);
            return;
        }

        // Stores elements already used at current level
        unordered_set<int> used;

        for (int j = i; j < nums.size(); j++)
        {

            // Skip duplicates
            if (used.count(nums[j]))
                continue;

            used.insert(nums[j]);

            swap(nums[i], nums[j]);

            perm(nums, i + 1);

            // Backtracking
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {

        perm(nums, 0);

        return res;
    }
};