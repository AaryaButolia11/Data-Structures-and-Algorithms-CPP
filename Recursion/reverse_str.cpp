#include <iostream>
#include <string>
using namespace std;

void revStr(string &s, int start, int end)
{
    // base case
    if (start >= end)
        return;
    // swap the characters at start and end
    swap(s[start], s[end]);

    // recursive call for the remaining string
    revStr(s, start + 1, end - 1);
}
int main()
{
    string s;
    cin >> s;
    revStr(s, 0, s.length() - 1);
    cout << s << endl;
    return 0;
}