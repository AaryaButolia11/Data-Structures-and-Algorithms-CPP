#include <iostream>
#include <string>
using namespace std;
int main()
{
    string S;
    cin >> S;
    int len = S.length();
    if (S[0] == S[len - 1])
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}