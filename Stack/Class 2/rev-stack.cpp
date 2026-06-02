using namespace std;
#include <iostream>
#include <stack>

void insertAtBottom(stack<int> &st, int x)
{
    if (st.empty())
    {
        st.push(x);
        return;
    }

    int topEle = st.top();
    st.pop();

    insertAtBottom(st, x);

    st.push(topEle);
}
void revStack(stack<int> &st)
{
    if (st.empty())
        return;

    int topEle = st.top();
    st.pop();

    // reverse the remaining stack
    revStack(st);

    // insert the top element at the bottom of the reversed stack
    insertAtBottom(st, topEle);

    st.push(topEle);
}
int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    revStack(st);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}