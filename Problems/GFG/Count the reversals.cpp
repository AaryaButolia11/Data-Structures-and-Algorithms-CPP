class Solution
{
public:
    int countMinReversals(string s)
    {
        // code here
        // if odd sized string then not possible
        int n = s.size();
        int ans = 0;
        if (n % 2 != 0)
            return -1;
        // create a char stack to store
        stack<char> st;
        for (char ch : s)
        {
            // if we get any opening { keep it in stack.
            if (ch == '{')
                st.push(ch);
            else
            {
                // if we get } and top = } so we remove it.
                if (!st.empty() && st.top() == '{')
                    st.pop();
                else
                    // any other removed
                    st.push(ch);
            }
        }
        // if stack isnt empty!!
        while (!st.empty())
        {
            // pop first 2 ele from stack
            char a = st.top();
            st.pop();
            char b = st.top();
            st.pop();
            // if same add +1
            if (a == b)
                ans += 1;
            // if diff add +2
            else if (a != b)
                ans += 2;
        }
        return ans;
    }
};