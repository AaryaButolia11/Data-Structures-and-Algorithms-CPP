class Solution
{
public:
    vector<int> firstNegInt(vector<int> &arr, int k)
    {
        deque<int> q;
        vector<int> ans;

        int n = arr.size();

        // First window
        for (int i = 0; i < k; i++)
        {
            if (arr[i] < 0)
            {
                q.push_back(i);
            }
        }

        // Remaining windows
        for (int i = k; i < n; i++)
        {

            // Answer for previous window
            if (q.empty())
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(arr[q.front()]);
            }

            // Remove out-of-window indices
            while (!q.empty() && (i - q.front() >= k))
            {
                q.pop_front();
            }

            // Add current element if negative
            if (arr[i] < 0)
            {
                q.push_back(i);
            }
        }

        // Last window
        if (q.empty())
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(arr[q.front()]);
        }

        return ans;
    }
};