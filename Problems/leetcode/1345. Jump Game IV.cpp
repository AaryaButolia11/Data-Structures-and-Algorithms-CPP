// Approach : Breadth First Search (BFS)
//
// Intuition:
// Treat each index as a node in a graph.
//
// From index i, we can move to:
// 1. i + 1
// 2. i - 1
// 3. Any index j where arr[i] == arr[j]
//
// Since we need minimum jumps/steps,
// BFS is the best choice because BFS always
// gives shortest path in an unweighted graph.
//
// Time Complexity  : O(n)
// Space Complexity : O(n)

class Solution
{
public:
    int minJumps(vector<int> &arr)
    {

        int n = arr.size();

        // If array has only one element,
        // we are already at the last index
        if (n == 1)
            return 0;

        // -------------------------------------------------
        // Map : value -> all indices having that value
        //
        // Example:
        // arr = [100,-23,-23,404,100]
        //
        // mp[100] = [0,4]
        // mp[-23] = [1,2]
        // mp[404] = [3]
        //
        // This helps us quickly jump to indices
        // having same value.
        // -------------------------------------------------
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++)
        {
            mp[arr[i]].push_back(i);
        }

        // -------------------------------------------------
        // Visited array
        //
        // visited[i] = true means
        // index i has already been processed.
        //
        // Prevents infinite revisits and extra work.
        // -------------------------------------------------
        vector<bool> visited(n, false);

        // -------------------------------------------------
        // BFS Queue
        //
        // Stores indices to process.
        // -------------------------------------------------
        queue<int> que;

        // Start BFS from index 0
        que.push(0);
        visited[0] = true;

        // Number of jumps taken
        int steps = 0;

        // -------------------------------------------------
        // Standard BFS
        // -------------------------------------------------
        while (!que.empty())
        {

            // Current BFS level size
            int size = que.size();

            // Process one complete level
            while (size--)
            {

                int curr = que.front();
                que.pop();

                // -------------------------------------------------
                // If we reached last index,
                // return minimum steps
                // -------------------------------------------------
                if (curr == n - 1)
                {
                    return steps;
                }

                // =================================================
                // 1. Move to left index (curr - 1)
                // =================================================
                int left = curr - 1;

                if (left >= 0 && !visited[left])
                {

                    visited[left] = true;
                    que.push(left);
                }

                // =================================================
                // 2. Move to right index (curr + 1)
                // =================================================
                int right = curr + 1;

                if (right < n && !visited[right])
                {

                    visited[right] = true;
                    que.push(right);
                }

                // =================================================
                // 3. Jump to all indices having same value
                // =================================================
                //
                // Example:
                // If arr[curr] = 23
                //
                // then mp[23] may contain:
                // [5,6,7]
                //
                // We can jump to all of them
                // in one step.
                // =================================================
                for (const int &idx : mp[arr[curr]])
                {

                    if (!visited[idx])
                    {

                        visited[idx] = true;
                        que.push(idx);
                    }
                }

                // =================================================
                // IMPORTANT OPTIMIZATION
                // =================================================
                //
                // After processing all indices having
                // value arr[curr], we erase it.
                //
                // Why?
                //
                // Suppose:
                // arr = [7,7,7,7,7]
                //
                // Without erase, every time we visit
                // a 7, we again traverse all indices.
                //
                // That leads to O(n²) and causes TLE.
                //
                // By erasing:
                // each value-group is processed only once.
                // =================================================
                mp.erase(arr[curr]);
            }

            // -------------------------------------------------
            // One BFS level completed
            //
            // Means one jump completed
            // -------------------------------------------------
            steps++;
        }

        // This line will never practically execute
        // because problem guarantees reachability
        return -1;
    }
};