#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    string str = "This is my first message";
    string word = "Babbar";

    str.replace(0, 2, word);
    cout << str << endl;
    return 0;
}
