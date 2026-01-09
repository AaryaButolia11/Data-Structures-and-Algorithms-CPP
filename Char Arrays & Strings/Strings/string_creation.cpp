#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    string str;
    // cin >> str;

    // to accept spaces use getline(cin,str);
    getline(cin, str);
    cout << str << endl;

    cout << "Length: " << str.length() << endl; // prints the length of the string
    cout << "Empty: " << str.empty() << endl;   // prints the length of the string
    str.push_back('@');                         // prints the length of the string
    cout << str << endl;
    str.pop_back(); // prints the length of the string
    cout << str << endl;

    cout << str.substr(0, 6) << endl; // prints the substring from index 0 to 6
    return 0;
}