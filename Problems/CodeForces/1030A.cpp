#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n; // Number of people

    int opinion;

    for (int i = 0; i < n; i++)
    {
        cin >> opinion; // Read each opinion

        if (opinion == 1) // If anyone says hard
        {
            cout << "HARD" << endl;
            return 0; // Stop immediately
        }
    }

    // If no one said hard
    cout << "EASY" << endl;

    return 0;
}