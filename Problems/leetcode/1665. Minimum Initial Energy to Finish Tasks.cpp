class Solution
{
public:
    int minimumEffort(vector<vector<int>> &tasks)
    {

        /*
            Each task = [actual, minimum]

            actual  -> energy spent after completing task
            minimum -> minimum energy needed to START task

            Greedy Idea:
            ----------------
            Tasks which require larger "extra energy"
            should be done earlier.

            extra energy = minimum - actual

            So we sort tasks based on:
                (minimum - actual)
        */

        sort(tasks.begin(), tasks.end(),
             [](const vector<int> &a, const vector<int> &b)
             {
                 // sort by (minimum - actual)
                 return (a[1] - a[0]) < (b[1] - b[0]);
             });

        /*
            ans = minimum initial energy required
            to complete tasks processed so far
        */
        int ans = 0;

        for (const auto &task : tasks)
        {

            int actual = task[0];
            int minimum = task[1];

            /*
                To perform current task first:

                1. We need at least 'minimum'
                   energy to START it.

                2. After spending 'actual',
                   we must still have enough
                   energy (= ans) to complete
                   remaining tasks.

                   So:
                        energy - actual >= ans

                   => energy >= ans + actual

                Therefore required energy is:

                    max(minimum, ans + actual)
            */

            ans = max(ans + actual, minimum);
        }

        // final minimum initial energy required
        return ans;
    }
};