#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // vector creations
    vector<int> arr;
    // int ans = sizeof(arr) / sizeof(int);
    // cout << ans << endl;
    // cout << arr.size() << endl;     // how many elements are stored in vector
    // cout << arr.capacity() << endl; // how many elements can be stored in vector

    // insert
    // arr.push_back(5);
    // arr.push_back(6);
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // arr.pop_back();

    // by default sets all to zero
    // vector<int> brr(10);

    // to set a specific value
    vector<int> brr(10, -1);
    cout << brr.size() << endl;     // how many elements are stored in vector
    cout << brr.capacity() << endl; // how many elements can be stored in vector
    for (int i = 0; i < brr.size(); i++)
    {
        cout << brr[i] << " ";
    }
    cout << endl;

    cout << "Vector brr is empty: " << brr.empty() << endl;

    vector<int> drr;
    cout << "Vector drr is empty: " << drr.empty() << endl;
    return 0;
}
