#include <iostream>
#include <string>
using namespace std;
void removeOccRE(string &s, string &part)
{
    int found = s.find(part);
    if (found != string::npos)
    {

        string left = s.substr(0, found);
        string right = s.substr(found + part.size(), s.size());
        s = left + right;
        removeOccRE(s, part);
    }
    else
    {
        return;
    }
}
int main()
{
    string s, part;
    cin >> s >> part;
    removeOccRE(s, part);
    cout << s;
    return 0;
}

// TC -> O(n*m) where n is the length of the string and m is the length of the substring
// SC -> O(n) due to recursive call stack and string manipulation