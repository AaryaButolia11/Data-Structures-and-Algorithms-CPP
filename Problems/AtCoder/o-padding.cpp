#include <iostream>
using namespace std;
int main()
{
    int n;
    string s;
    cin >> n >> s;
    // Read the length of the string and the string itself
    int str_len = n - s.size(); // Calculate the number of 'o' characters needed
    for (int i = 0; i < str_len; i++)
    {
        cout << "o";
    }
    cout << s << endl;

    return 0;
}