#include <iostream>
#include <stack>
using namespace std;
int main()
{
    // creation of stack
    stack<int> s;

    // to push ele
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    // to pop ele
    s.pop();

    // to get top ele
    cout << "Top ele is " << s.top() << endl;

    // size
    cout << "Size of stack is " << s.size() << endl;

    // to check if stack is empty
    if (s.empty())
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl; 
    return 0;
}