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

    while (s.empty() == 0)
    {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}