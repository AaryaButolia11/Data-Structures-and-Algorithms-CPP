class Solution
{
public:
    typedef unsigned long long ll;

    // Previous Smaller Element (Left)
    vector<int> getNSL(vector<int> &arr, int n)
    {
        vector<int> res(n);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }

            res[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return res;
    }

    // Next Smaller Element (Right)
    vector<int> getNSR(vector<int> &arr, int n)
    {
        vector<int> res(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            res[i] = st.empty() ? n : st.top(); // n instead of -1
            st.push(i);
        }

        return res;
    }

    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> NSL = getNSL(arr, n);
        vector<int> NSR = getNSR(arr, n);

        long long sum = 0;
        const int MOD = 1e9 + 7;

        for (int i = 0; i < n; i++)
        {
            long long left = i - NSL[i];
            long long right = NSR[i] - i;

            long long contribution =
                ((left * right) % MOD * arr[i]) % MOD;

            sum = (sum + contribution) % MOD;
        }

        return sum;
    }
};
