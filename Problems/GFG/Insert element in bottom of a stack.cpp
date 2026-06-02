class Solution
{
public:
    void insert(stack<int> &st, int x)
    {
        if (st.empty())
        {
            st.push(x);
            return;
        }

        int topEle = st.top();
        st.pop();

        insert(st, x);

        st.push(topEle);
    }

    stack<int> insertAtBottom(stack<int> st, int x)
    {
        insert(st, x);
        return st;
    }
};