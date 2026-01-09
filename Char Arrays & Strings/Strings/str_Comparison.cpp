#include <iostream>
#include <string>
using namespace std;

bool compareStrings(const string &a, const string &b)
{
    if (a.length() != b.length())
        return false;

    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string a = "Love";
    string b = "love";

    if (compareStrings(a, b))
    {
        cout << "Both strings are equal" << endl;
    }
    else
    {
        cout << "Both strings are not equal" << endl;
    }

    // if (a.compare(b) == 0)
    // {
    //     cout << "Both strings are equal" << endl;
    // }
    // else if (a.compare(b) < 0)
    // {
    //     cout << "String a is less than string b" << endl;
    // }
    // else
    // {
    //     cout << "String a is greater than string b" << endl;
    // }
    return 0;
}