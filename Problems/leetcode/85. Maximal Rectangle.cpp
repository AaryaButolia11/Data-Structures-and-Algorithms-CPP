class Solution
{
public:
    vector<int> nextSmaller(vector<int> &input)
    {
        stack<int> st;
        // push -1 to compare with
        st.push(-1);
        vector<int> ans(input.size());
        // go from left to right
        for (int i = input.size() - 1; i >= 0; --i)
        {
            int curr = input[i];
            // pop ele till we find any ele < curr
            while (st.top() != -1 && input[st.top()] >= curr)
            {
                st.pop();
            }
            // put top val which is smaller than curr in ans
            ans[i] = st.top();
            // push this idx for comparison
            st.push(i);
        }
        return ans;
    }
    vector<int> prevSmaller(vector<int> &input)
    {
        stack<int> st;
        st.push(-1);
        vector<int> ans(input.size());
        for (int i = 0; i < input.size(); ++i)
        {
            int curr = input[i];
            while (st.top() != -1 && input[st.top()] >= curr)
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int> &heights)
    {
        vector<int> prev = prevSmaller(heights);
        vector<int> next = nextSmaller(heights);
        int size = heights.size();
        int maxAr = INT_MIN;
        for (int i = 0; i < heights.size(); ++i)
        {
            // get h from arr
            int len = heights[i];
            // in next change -1 -> size as we require to calc from R->L so we need size to subtract it from
            if (next[i] == -1)
                next[i] = size;
            // widht=n-p-1;
            int wid = next[i] - prev[i] - 1;
            int ar = len * wid;
            // save max area ans!
            maxAr = max(maxAr, ar);
        }
        // returning ans!!
        return maxAr;
    }

    int maximalRectangle(vector<vector<char>> &matrix)
    {

        if (matrix.empty())
            return 0;

        vector<vector<int>> v;

        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++)
        {
            vector<int> t;
            for (int j = 0; j < m; j++)
            {
                t.push_back(matrix[i][j] - '0');
            }
            v.push_back(t);
        }

        int area = largestRectangleArea(v[0]);

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (v[i][j])
                {
                    v[i][j] += v[i - 1][j];
                }
                else
                {
                    v[i][j] = 0;
                }
            }

            area = max(area, largestRectangleArea(v[i]));
        }

        return area;
    }
};