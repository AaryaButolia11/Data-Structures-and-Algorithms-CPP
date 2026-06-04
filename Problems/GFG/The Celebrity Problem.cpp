class Solution
{
public:
    int celebrity(vector<vector<int>> &M)
    {
        int n = M.size();

        stack<int> st;

        // Push all persons
        for (int i = 0; i < n; i++)
        {
            st.push(i);
        }

        // Find potential celebrity
        while (st.size() > 1)
        {
            int a = st.top();
            st.pop();

            int b = st.top();
            st.pop();

            if (M[a][b] == 1)
            {
                // a knows b => a can't be celebrity
                st.push(b);
            }
            else
            {
                // a doesn't know b => b can't be celebrity
                st.push(a);
            }
        }

        int c = st.top();

        // Celebrity should not know anyone
        for (int i = 0; i < n; i++)
        {
            if (i != c && M[c][i] == 1)
            {
                return -1;
            }
        }

        // Everyone should know celebrity
        for (int i = 0; i < n; i++)
        {
            if (i != c && M[i][c] == 0)
            {
                return -1;
            }
        }

        return c;
    }
};