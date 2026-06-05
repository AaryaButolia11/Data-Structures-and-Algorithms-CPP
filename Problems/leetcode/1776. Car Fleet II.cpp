class Solution
{
public:
    vector<double> getCollisionTimes(vector<vector<int>> &cars)
    {

        // Stores collision time for each car
        vector<double> ans(cars.size(), -1);

        // Monotonic stack storing indices of cars
        stack<int> st;

        // Process cars from right to left
        for (int i = cars.size() - 1; i >= 0; --i)
        {

            // Remove cars that current car can never catch
            // because they are moving faster or at same speed
            while (!st.empty() && cars[st.top()][1] >= cars[i][1])
            {
                st.pop();
            }

            // Check remaining possible collision candidates
            while (!st.empty())
            {

                // Time = Distance / Relative Speed
                double colTime =
                    (double)(cars[st.top()][0] - cars[i][0]) /
                    (cars[i][1] - cars[st.top()][1]);

                // Valid collision if:
                // 1. front car never collides
                // OR
                // 2. current car reaches it before it collides
                if (ans[st.top()] == -1 ||
                    colTime <= ans[st.top()])
                {

                    ans[i] = colTime;
                    break;
                }

                // Front car changes speed before current reaches it
                st.pop();
            }

            // Current car becomes candidate for cars behind it
            st.push(i);
        }

        return ans;
    }
};