// A null character is placed at end if we allot a whole string together showcasing end of any string
#include <iostream>
using namespace std;
int main()
{
    char name[100];
    cin >> name;
    for (int i = 0; i < 7; i++)
    {
        cout << "Index of : " << i << " value: " << name[i] << endl;
    }

    // finding value of null character
    int value = (int)name[6];
    cout << "Value of null character: " << value << endl;
    return 0;
}