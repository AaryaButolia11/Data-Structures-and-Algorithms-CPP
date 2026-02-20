#include <iostream>
using namespace std;
#include <algorithm> // For reverse()

int main()
{
    string s, t;
    cin >> s;
    cin >> t; // Input the two numbers
    reverse(s.begin(), s.end());
    if (s == t)
        cout << "YES" << endl; // Output YES if the reversed first number matches the second
    else
        cout << "NO" << endl; // Output NO if no common character is found
    return 0;
}