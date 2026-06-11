#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void revQ(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }

    int ele = q.front();
    q.pop();
    revQ(q);
    q.push(ele);
}
int main()
{
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    revQ(q);

    cout << "Printing rev Q: " << endl;
    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}