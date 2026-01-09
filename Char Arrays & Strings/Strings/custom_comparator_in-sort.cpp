#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

// Custom comparator function for sorting in descending order
bool customComparator(char a, char b)
{
    return a > b; // Change to '<' for ascending order
}

int main()
{
    string s = "babbar";
    sort(s.begin(), s.end(), customComparator); // ascending order

    cout << s << endl;
    return 0;
}