#include <iostream>
#include <string> // Include the string header
using namespace std;

int main()
{
    string str1 = "Hello World"; // Use std::string instead of char array
    str1.erase(5, 6);            // Erases " World" from str1
    cout << str1 << endl;        // Output: Hello
    return 0;
}