#include <vector>
#include <algorithm> // Required for std::sort

class Solution {
public:
    // Helper function to check if it's possible to place k cows
    // with at least 'min_dist' distance between them.
    // 'stalls' is passed by const reference to avoid copying.
    bool isSoln(const std::vector<int>& stalls, int k, int min_dist) {
        int cowsPlaced = 1; // Place the first cow at the first stall
        int lastCowPosition = stalls[0]; // Position of the last placed cow

        // Iterate through the stalls to place remaining cows
        for (int i = 1; i < stalls.size(); i++) {
            // If the current stall is far enough from the last placed cow,
            // place another cow.
            if (stalls[i] - lastCowPosition >= min_dist) {
                cowsPlaced++;
                lastCowPosition = stalls[i]; // Update the position of the last placed cow

                // If we have placed 'k' cows, then 'min_dist' is achievable
                if (cowsPlaced == k) {
                    return true;
                }
            }
        }
        // If we couldn't place 'k' cows with 'min_dist' separation
        return false;
    }

    // Main function to find the maximum possible minimum distance between aggressive cows.
    int aggressiveCows(std::vector<int> &stalls, int k) {
        // Sort the stalls to ensure they are in ascending order.
        // This is crucial for the greedy placement logic in isSoln and binary search.
        std::sort(stalls.begin(), stalls.end());

        // Define the search space for the minimum distance:
        // 'start' is the minimum possible distance (0, or 1 if stalls are distinct).
        // 'end' is the maximum possible distance (distance between first and last stall).
        int start = 0;
        int end = stalls[stalls.size() - 1] - stalls[0];

        int ans = -1; // Initialize answer to -1 (or 0, depending on problem constraints)

        // Perform binary search on the possible distances
        while (start <= end) {
            // Calculate mid-point safely to prevent integer overflow
            int mid = start + (end - start) / 2;

            // Check if it's possible to place 'k' cows with 'mid' distance
            if (isSoln(stalls, k, mid)) {
                // If 'mid' distance is achievable, it's a potential answer.
                // Try for a larger distance by moving 'start' to 'mid + 1'.
                ans = mid;
                start = mid + 1;
            } else {
                // If 'mid' distance is not achievable, we need to reduce the distance.
                // Move 'end' to 'mid - 1'.
                end = mid - 1;
            }
        }
        return ans; // Return the maximum achievable minimum distance
    }
};
