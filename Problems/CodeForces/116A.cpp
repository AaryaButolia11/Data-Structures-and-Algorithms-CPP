#include <iostream>
using namespace std;
int main()
{
    int n; // No.of stops
    cin >> n;
    int a, b;
    int passengers = 0;
    int capacity = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;   // a = no. of passengers leaving, b = no. of passengers entering
        passengers -= a; // Passengers leaving
        passengers += b; // Passengers entering
        if (passengers > capacity)
        {
            capacity = passengers; // Update the maximum capacity needed
        }
    }
    cout << capacity << endl; // Output the minimum capacity required for the tram
    return 0;
}