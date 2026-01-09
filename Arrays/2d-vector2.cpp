#include <vector>
#include <iostream>
using namespace std;
int main()
{
    vector<vector<int>> arr(5, vector<int>(5, -8));

    // arr.push_back(a);
    // arr.push_back(b);
    // arr.push_back(c);

    cout << arr[2][3] << endl;
    ;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}