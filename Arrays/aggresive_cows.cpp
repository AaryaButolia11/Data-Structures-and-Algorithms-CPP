#include <vector>
#include <algorithm> // Required for std::sort
#include <iostream>  // Required for std::cout, std::endl (if needed for debugging)
// Using namespace std; is generally discouraged in header files or large projects
// to avoid name collisions, but it's common in competitive programming.
using namespace std;

class Solution
{
public:
    bool isSoln(const vector<int> &stalls, int k, int min_dist)
    {
        int cowsPlaced = 1;              // Start by placing the first cow at the first stall
        int lastCowPosition = stalls[0]; // Keep track of the position of the last placed cow

        // Iterate through the remaining stalls to place the other k-1 cows
        for (int i = 1; i < stalls.size(); i++)
        {
            // If the current stall is at least 'min_dist' away from the last placed cow,
            // we can place another cow here.
            if (stalls[i] - lastCowPosition >= min_dist)
            {
                cowsPlaced++;                // Increment the count of placed cows
                lastCowPosition = stalls[i]; // Update the position of the last placed cow

                // If we have successfully placed 'k' cows, then 'min_dist' is achievable.
                if (cowsPlaced == k)
                {
                    return true;
                }
            }
        }
        // If we finish iterating and haven't placed 'k' cows, then 'min_dist' is not achievable.
        return false;
    }

    /**
     * @brief Finds the largest minimum distance possible between 'k' aggressive cows
     * that can be placed in the given 'stalls'.
     *
     * This problem is solved using binary search on the answer space (the minimum distance).
     * The possible minimum distances range from 0 (or 1, if distinct stalls) to the
     * distance between the first and last stall. For each 'mid' distance, the 'isSoln'
     * helper function checks its feasibility.
     *
     * @param stalls A vector of stall positions. This vector will be sorted.
     * @param k The number of cows to place.
     * @return The maximum possible minimum distance between any two cows.
     */
    int aggressiveCows(vector<int> &stalls, int k)
    {
        // Step 1: Sort the stall positions. This is crucial because:
        // a) The 'isSoln' function relies on stalls being in increasing order for greedy placement.
        // b) It helps define the search space for binary search.
        sort(stalls.begin(), stalls.end());

        // Step 2: Define the search space for the binary search.
        // 'start' represents the minimum possible distance (e.g., 0 or 1).
        // 'end' represents the maximum possible distance (distance between the first and last stall).
        int start = 0;
        int end = stalls[stalls.size() - 1] - stalls[0];

        int ans = -1; // Initialize the answer. This will store the maximum feasible minimum distance.

        // Step 3: Perform binary search on the possible minimum distances.
        // We are looking for the largest 'mid' for which 'isSoln(mid)' is true.
        while (start <= end)
        {
            // Calculate the middle point safely to prevent integer overflow.
            // This is the correct way: start + (end - start) / 2
            int mid = start + (end - start) / 2;

            // Check if it's possible to place 'k' cows with 'mid' distance apart.
            if (isSoln(stalls, k, mid))
            {
                // If 'mid' distance is achievable, it means this 'mid' is a possible answer.
                // We try to find an even larger distance, so we store 'mid' as a potential answer
                // and search in the upper half [mid + 1, end].
                ans = mid;
                start = mid + 1;
            }
            else
            {
                // If 'mid' distance is NOT achievable, it means 'mid' is too large.
                // We need to reduce the distance, so we search in the lower half [start, mid - 1].
                end = mid - 1;
            }
        }
        // After the binary search, 'ans' will hold the maximum possible minimum distance.
        return ans;
    }
};
