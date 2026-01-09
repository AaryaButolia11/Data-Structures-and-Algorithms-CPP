#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;
int getLine(char name[])
{
    int length = 0;
    int i = 0;
    while (name[i] != '\0')
    {
        length++;
        i++;
    }
    return length;
}
int main()
{
    char arr[100];
    cin.getline(arr, 100);
    int length = getLine(arr);
    cout << "Length of the string is: " << length << endl;
    cout << "length of the string is: " << strlen(arr) << endl;
    return 0;
}