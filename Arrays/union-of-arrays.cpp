#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int arr[] = {1, 3, 5, 7, 9};
    int sizea = 5;
    int brr[] = {2, 4, 6, 8, 10};
    int sizeb = 5;
    vector<int> ans;
    for (int i = 0; i < sizea; i++)
    {
        ans.push_back(arr[i]);
    }
    cout << endl;
    for (int i = 0; i < sizeb; i++)
    {
        ans.push_back(brr[i]);
    }

    cout << "Printing combined array: " << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}