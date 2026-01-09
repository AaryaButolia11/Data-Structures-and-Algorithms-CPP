#include <iostream>
using namespace std;
int main()
{
    char ch[100];
    // cout << "enter your name: " << endl;
    // cin >> name;
    // cout << "your name is: " << name << endl;

    ch[0] = 'a';
    ch[1] = 'b';
    cin >> ch[2];
    cout << ch[0] << ch[1] << ch[2] << endl;
    return 0;
}