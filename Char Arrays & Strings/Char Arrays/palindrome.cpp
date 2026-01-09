#include <iostream>
#include <string.h>

bool checkPalindrome(char word[])
{
    int i = 0;
    int n = strlen(word);
    int j = n - 1;
    while (i <= j)
    {
        if (word[i] != word[j])
        {
            return false; // Not a palindrome
        }
        i++;
        j--;
    }

    return true; // Is a palindrome
}
using namespace std;
int main()
{
    char word[100];
    cout << "Enter a word: ";
    cin.getline(word, 100); // Read a line of input into word
    cout << "You entered: " << word << endl;
    cout << "Checking if the word is a palindrome..." << endl;
    if (checkPalindrome(word))
    {
        cout << "The word is a palindrome." << endl;
    }
    else
    {
        cout << "The word is not a palindrome." << endl;
    }
    return 0;
}