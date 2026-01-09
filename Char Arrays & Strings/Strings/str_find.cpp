#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    string sentence = "hello world";
    string target = "12";
    // cout << sentence.find(target) << endl; // prints the index of the first occurrence of target in sentence
    if (sentence.find(target) != string::npos)
    {
        cout << "Found at index: " << sentence.find(target) << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }
    return 0;
}