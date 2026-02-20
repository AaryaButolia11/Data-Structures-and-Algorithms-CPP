#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n; // Input the number of games
    string s;
    cin >> s; // Input the string
    int A_wins = 0;
    int D_wins = 0;
    for (auto c : s)
    {
        if (c == 'A')
            A_wins++;
        else
            D_wins++;
    }
    if (A_wins > D_wins)
        cout << "Anton" << endl; // Output Anton if A wins more
    else if (D_wins > A_wins)
        cout << "Danik" << endl; // Output Danik if D wins more
    else
        cout << "Friendship" << endl; // Output Friendship if it's a tie
    return 0;
}