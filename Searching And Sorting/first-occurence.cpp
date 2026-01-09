#include <iostream>
#include <vector>
using namespace std;

int firstOccurence(vector<int> v, int target)
{
    int s = 0;
    int e = v.size() - 1;
    int ans = -1;

    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (v[mid] == target)
        {
            ans = mid;
            e = mid - 1; // Move left to find earlier occurrence
        }
        else if (target > v[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> v{1, 3, 4, 4, 4, 4, 4, 6, 7};
    int target;
    cin >> target;
    int indexOfFirstOccurence = firstOccurence(v, target);
    cout << "First occurrence is at index: " << indexOfFirstOccurence << endl;
    return 0;
}
