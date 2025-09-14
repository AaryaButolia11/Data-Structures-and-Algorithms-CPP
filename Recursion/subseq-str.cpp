#include <iostream>
using namespace std;
#include <string>
void printSubSeq(string str, string output, int i)
{
    // base case
    if (i >= str.length())
    {
        cout <<output << endl;
        return;
    }
    // exclude
    printSubSeq(str, output, i + 1);

    // include
    // below line is for concatenation of output string with the ith character
    output.push_back(str[i]);
    printSubSeq(str, output, i + 1);
}

int main()
{
    string str = "abc";
    string output = "";
    int i = 0;
    printSubSeq(str, output, i);
    return 0;
}