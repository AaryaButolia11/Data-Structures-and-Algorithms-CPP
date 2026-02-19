#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s; // Input the word

    int lower = 0; // Counter for lowercase letters
    int upper = 0; // Counter for uppercase letters

    // Count lowercase and uppercase letters
    for (int i = 0; i < s.size(); i++)
    {
        if (isupper(s[i])) // Check if character is uppercase
            upper++;
        else // Otherwise it is lowercase
            lower++;
    }

    // If uppercase letters are more, convert entire string to uppercase
    if (upper > lower)
    {
        for (int i = 0; i < s.size(); i++)
            s[i] = toupper(s[i]);
    }
    else // If lowercase are more OR equal → convert to lowercase
    {
        for (int i = 0; i < s.size(); i++)
            s[i] = tolower(s[i]);
    }

    // Output the corrected word
    cout << s;

    return 0;
}
