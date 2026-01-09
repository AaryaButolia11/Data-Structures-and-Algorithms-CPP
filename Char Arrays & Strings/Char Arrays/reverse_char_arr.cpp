#include <iostream>
#include <string.h> // For strlen and other C-style string functions (or <cstring>)
// #include <cstring> // This is also good to include, but string.h is sufficient for strlen
using namespace std;

void reverseCharArray(char arr[])
{
    int start = 0;
    int end = strlen(arr) - 1; // Correctly gets the last index
    while (start <= end)
    {
        // Swap characters at start and end
        char temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // Move pointers inward
        start++;
        end--;
    }
}

int main()
{
    cout << "Enter a string: "; // Prompt the user
    char arr[100];
    cin.getline(arr, 100); // Reads a line of input into arr

    cout << "Original array: " << arr << endl; // Show the original string

    reverseCharArray(arr); // Call the function to reverse the array in-place

    cout << "Reversed array: " << arr << endl; // Print the modified (reversed) array

    return 0;
}