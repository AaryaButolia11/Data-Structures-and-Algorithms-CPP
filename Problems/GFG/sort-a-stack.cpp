class Solution
{
public:
    void insertSort(stack<int> &st, int tg)
    {
        // Base case
        if (st.empty())
        {
            st.push(tg);
            return;
        }

        // Correct position found
        if (st.top() < tg)
        {
            st.push(tg);
            return;
        }

        int topEle = st.top();
        st.pop();

        insertSort(st, tg);

        st.push(topEle);
    }

    void sortStack(stack<int> &st)
    {
        if (st.empty())
            return;

        int topEle = st.top();
        st.pop();

        sortStack(st);

        insertSort(st, topEle);
    }
};