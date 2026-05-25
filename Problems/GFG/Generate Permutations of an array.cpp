class Solution
{
public:
    vector<vector<int>> res;
    void printPerm(vector<int> &arr, int i)
    {
        if (i >= arr.size())
        {
            res.push_back(arr);
            return;
        }

        for (int j = i; j < arr.size(); j++)
        {
            swap(arr[i], arr[j]);
            printPerm(arr, i + 1);
            swap(arr[i], arr[j]);
        }
    }
    vector<vector<int>> permuteDist(vector<int> &arr)
    {
        // code here
        int i = 0;
        printPerm(arr, i);
        return res;
    }
};