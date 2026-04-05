#include <iostream>
using namespace std;
void lastOccLtr(string s, char x, int i, int &lastOcc)
{
    // base case
    if (i >= s.length())
    {
        return;
    }

    // recursive case
    if (s[i] == x)
    {
        lastOcc = i;
    }
    lastOccLtr(s, x, i + 1, lastOcc);
}
int main()
{
    string s;
    cin >> s;
    char x;
    cin >> x;
    int lastOcc = -1;
    lastOccLtr(s, x, 0, lastOcc);
    cout << lastOcc;
    return 0;
}