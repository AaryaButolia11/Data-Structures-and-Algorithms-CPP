class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq;
        vector<int> ans;

        // first window traversal
        for (int i = 0; i < k; i++)
        {
            while (!dq.empty() && nums[i] >= nums[dq.back()])
            {
                dq.pop_back();
            }
            // insert idx
            dq.push_back(i);
        }
        // store ans for first window
        ans.push_back(nums[dq.front()]);

        // remaining loops
        for (int i = k; i < nums.size(); i++)
        {
            //  remove out of window ele
            if (!dq.empty() && i - dq.front() >= k)
                dq.pop_front();

            // curr ele remove small ele
            while (!dq.empty() && nums[i] >= nums[dq.back()])
            {
                dq.pop_back();
            }
            // insert idx
            dq.push_back(i);

            // curr window ans
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};