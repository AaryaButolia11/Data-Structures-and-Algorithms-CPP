#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    // create a map with int as key and char as value
    map<int, char> map;

    map[0] = 'a';
    map[1] = 'b';
    map[2] = 'c';
    map[3] = 'd';

    cout << "The map contains:\n"
         << "Key 0: "
         << map[0] << "\n";
    return 0;
}