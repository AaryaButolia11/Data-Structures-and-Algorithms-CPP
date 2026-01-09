#include <iostream>
#include <vector>
using namespace std;

int findUnique(vector<int> arr)
{
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}
int main()
{
    int n;
    cout << "Enter size of array:  " << endl;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << "Enter elem: ";
        cin >> arr[i];
    }

    int uniqueElem = findUnique(arr);
    cout << "unique element is: " << uniqueElem << endl;
    return 0;
}