#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void revQk(queue<int> &q, int k, int rem, int n)
{
    if (k <= 0 || k > n)
    {
        return;
    }
    stack<int> st;
    while (k--)
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    while (rem--)
    {
        int ele = q.front();
        q.pop();
        q.push(ele);
    }
}
int main()
{
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(12);
    q.push(15);
    int k = 6;
    int n = q.size();
    int rem = n - k;
    revQk(q, k, rem, n);

    cout << "Printing rev Q: " << endl;
    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}