#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    cin >> s; // Input the string
    int luckyCount = 0;
    for (auto c : s)
    {
        if (c == '4' || c == '7')
            luckyCount++; // Count the number of lucky digits
    }
    if (luckyCount == 4 || luckyCount == 7)
        cout << "YES" << endl; // Output YES if the count is 4 or 7
    else
        cout << "NO" << endl; // Output NO otherwise
    return 0;
}