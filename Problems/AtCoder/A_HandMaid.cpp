#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    cin >> s;
    s[0] = tolower(s[0]);
    string res = "Of" + s;
    cout << res << endl;
    return 0;
}