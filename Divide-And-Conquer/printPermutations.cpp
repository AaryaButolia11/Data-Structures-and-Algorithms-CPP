#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printPerm(string &str, int i)
{
    // base case
    if (i >= str.length())
    {z
        cout << str << " ";
        return;
    }

    // swapping
    for (int j = i; j < str.length(); j++)
    {
        swap(str[i], str[j]);
        printPerm(str, i + 1);
        // backtracking
        swap(str[i], str[j]);
    }
}
int main()
{
    string str = "abc";
    int i = 0;
    cout << "Permutations of " << str << " are: ";
    printPerm(str, i);
    return 0;
}