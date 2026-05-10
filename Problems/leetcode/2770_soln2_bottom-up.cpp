#include <iostream>
#include <vector>
#include <stdint.h>
#include <climits> // For INT_MIN

using namespace std;

int main()
{
    // Input array representing jump values
    vector<int> jumps = {1, 3, 6, 4, 1, 2};

    // Maximum allowed difference between two positions
    int target = 2;

    // Size of array
    int n = jumps.size();

    /*
        DP array:
        t[i] stores the maximum jumps possible
        starting from index i.

        INT_MIN means the index is currently unreachable.
    */
    vector<int> t(n + 1, INT_MIN);

    // Base case:
    // Last index requires 0 jumps to reach itself
    t[n - 1] = 0;

    // Traverse from second last index to first
    for (int i = n - 2; i >= 0; i--)
    {
        // Try jumping from index i to every index j > i
        for (int j = i + 1; j < n; j++)
        {
            /*
                Valid jump conditions:
                1. Difference between values <= target
                2. Destination index j must be reachable
            */
            if (abs(jumps[j] - jumps[i]) <= target && t[j] != INT_MIN)
            {
                // One jump to j + jumps possible from j
                int temp = 1 + t[j];

                // Store maximum jumps possible from index i
                t[i] = max(t[i], temp);
            }
        }
    }

    /*
        If t[0] is still negative,
        it means starting index cannot reach end.
    */
    cout << (t[0] < 0 ? -1 : t[0]);

    return 0;
}