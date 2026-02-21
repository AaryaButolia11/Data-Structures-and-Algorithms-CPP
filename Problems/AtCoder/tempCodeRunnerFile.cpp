#include <iostream>
using namespace std;
int main()
{
    int n;
    string s;
    cin >> n >> s;
    string ans = "";            // Read the length of the string and the string itself
    int str_len = n - s.size(); // Calculate the number of 'o' characters needed
    for (int i = 0; i < s.size(); i++)
    {
        ans += "o";
    }
    cout << ans + s;
    return 0;
}