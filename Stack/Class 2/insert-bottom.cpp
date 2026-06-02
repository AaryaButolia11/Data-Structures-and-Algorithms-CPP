#include <iostream>
#include <stack>
using namespace std;
void solve(stack<int> &s, int target)
{
    if (s.empty())
    {
        s.push(target);
        return;
    }
    int topEle = s.top();
    s.pop();
    solve(s, target);
    s.push(topEle);
}
void pushBottom(stack<int> &s)
{
    if (s.empty())
        return;
    int target = s.top();
    s.pop();
    solve(s, target);
}
void printStack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    printStack(s);
    pushBottom(s);
    printStack(s);

    return 0;
}