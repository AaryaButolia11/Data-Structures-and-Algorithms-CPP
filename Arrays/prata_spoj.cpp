#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

bool isSoln(const vector<int> &cooksRanks, int nP, int time)
{

    int currP = 0;
    for (int i = 0; i < cooksRanks.size(); i++)
    {
        int R = cooksRanks[i];
        int j = 1;
        int timeTaken = 0;
        while (true)
        {
            if (timeTaken + j * R <= time)
            {
                ++currP;
                timeTaken += j * R;
                ++j;
            }
            else
            {
                break;
            }
        }
        if (currP >= nP)
        {
            return true;
        }
    }
    return false;
}

int minTimeToCook(vector<int> &cooksRanks, int nP)
{
    int start = 0, highestRank = *max_element(cooksRanks.begin(), cooksRanks.end());
    int end = highestRank * (nP * (nP + 1)) / 2; // Maximum time needed if the slowest cook makes all pancakes
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        long long totalPancakes = 0;

        if (isSoln(cooksRanks, nP, mid))
        {
            ans = mid;     // Found a valid time
            end = mid - 1; // Try for a smaller time
        }
        else
        {
            start = mid + 1; // Try for a larger time
        }
    }
    return ans;
}

int main()
{
    int T;
    // cout << "Enter number of test cases: ";
    cin >> T;
    while (T--)
    {
        int nP, nC;
        // cout << "Enter number of pancakes and cooks: ";
        cin >> nP >> nC;
        vector<int> cooksRanks;
        while (nC--)
        {
            int x;
            cin >> x;
            // cout << "Enter cook's rank: ";
            cooksRanks.push_back(x);
        }
        cout << minTimeToCook(cooksRanks, nP) << endl;
    }
    return 0;
}