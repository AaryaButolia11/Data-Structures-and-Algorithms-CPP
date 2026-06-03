#include <iostream>
#include <stack>
using namespace std;

void insertSort(stack<int> &s, int target)
{
    if (s.empty())
    {
        s.push(target);
        return;
    }
    if (s.top() >= target)
    {
        s.push(target);
        return;
    }
    int topEle = s.top();
    s.pop();
    insertSort(s, target);
    s.push(topEle);
}

void sortStack(stack<int> &s)
{
    if (s.empty())
        return;
    int topEle = s.top();
    s.pop();
    sortStack(s);
    insertSort(s, topEle);
}

int main()
{
    stack<int> s;
    s.push(7);
    s.push(11);
    s.push(3);
    s.push(5);
    s.push(9);
    sortStack(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}