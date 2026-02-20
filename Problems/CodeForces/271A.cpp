#include <iostream>
using namespace std;
bool distinctDigits(int yr)
{
    bool used[10] = {false}; // Array to track used digits
    while (yr > 0)
    {
        int digit = yr % 10; // Get the last digit
        if (used[digit])
        {
            return false; // If the digit is already used, return false
        }
        used[digit] = true; // Mark the digit as used
        yr /= 10;           // Remove the last digit
    }
    return true; // All digits are distinct
}
int main()
{
    int y;
    cin >> y;
    y++; // Start checking from the next year
    while (true)
    {
        if (distinctDigits(y))
        {
            cout << y << endl; // Output the next year with distinct digits
            break;             // Exit the loop once we find the year
        }
        y++; // Move to the next year
    }
    return 0;
}