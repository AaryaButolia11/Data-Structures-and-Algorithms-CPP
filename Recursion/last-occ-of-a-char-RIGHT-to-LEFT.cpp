#include <iostream>
#include <string> // ✅ ADD THIS
using namespace std;

void lastOccLtr(string s, char x, int i, int &lastOcc)
{
    if (i < 0 || lastOcc != -1)
        return;

    if (s[i] == x)
    {
        lastOcc = i;
        return; // stop recursion
    }

    lastOccLtr(s, x, i - 1, lastOcc);
}
int main()
{
    string s;
    cin >> s;

    char x;
    cin >> x;

    int lastOcc = -1;
    lastOccLtr(s, x, s.size() - 1, lastOcc);

    cout << lastOcc;
}