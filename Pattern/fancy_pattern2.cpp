#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int r = 0; r < n; r++)
    {
        int c;
        {
            cout << c + 1;
        }
        for (int c = r; c >= 1; c--)
        {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}