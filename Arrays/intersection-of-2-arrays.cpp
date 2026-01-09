#include <vector>
#include <iostream>
using namespace std;
int main()
{
    vector<int> arr{1, 2, 3, 4, 6, 8};
    vector<int> brr{4, 4, 3, 7, 3, 8};
    vector<int> ans;

    for (int i = 0; i < arr.size(); i++)
    {
        int elem = arr[i];
        for (int j = 0; j < brr.size(); j++)
        {
            if (elem == brr[j])
            {
                brr[j] = -1;
                ans.push_back(elem);
            }
        }
    }

    for (auto value : ans)
    {
        cout << value << " ";
    }
    return 0;
}