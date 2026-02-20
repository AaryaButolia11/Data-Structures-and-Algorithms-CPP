#include <iostream>
using namespace std;
int main()
{
    int n, h;
    cin >> n >> h; // Input the number of friends and the height of the fence
    int width = 0; // Initialize the total width needed
    for (int i = 0; i < n; i++)
    {
        int height;
        cin >> height; // Input the height of each friend
        if (height > h)
        {
            width += 2; // If the friend's height is greater than the fence, they need 2 units of width
        }
        else
        {
            width += 1; // If the friend's height is less than or equal to the fence, they need 1 unit of width
        }
    }
    cout << width << endl; // print minimum required width

    return 0;
}