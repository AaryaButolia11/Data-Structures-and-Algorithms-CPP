#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<char> s;
    string str = "Hello World";
    for (int i = 0; i < str.size(); i++)
    {
        s.push(str[i]);
    }
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    cout << endl;
    return 0;
}