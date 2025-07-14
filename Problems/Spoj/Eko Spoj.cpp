#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
bool isPossibleSolution(vector<long long int> &trees, long long int m, long long int height)
{
    long long int totalWood = 0;
    for (long long int tree : trees)
    {
        if (tree > height)
        {
            totalWood += (tree - height);
        }
    }
    return totalWood >= m; // Check if we can get at least m wood
}

long long int maxSawBladeHeight(vector<long long int> &trees, long long int m)
{
    long long int start = 0, end, ans = -1;
    end = *max_element(trees.begin(), trees.end());
    while (start <= end)
    {
        long long int mid = start + (end - start) / 2;
        if (isPossibleSolution(trees, m, mid))
        {
            ans = mid;       // Found a valid height
            start = mid + 1; // Try for a higher height
        }
        else
        {
            end = mid - 1; // Try for a lower height
        }
    }
    return ans;
}

int main()
{

    long long int n, m;
    cin >> n >> m;
    vector<long long int> trees;
    while (n--)
    {
        long long int x;
        cin >> x;
        trees.push_back(x);
    }

    cout << maxSawBladeHeight(trees, m) << endl;
    return 0;
}
