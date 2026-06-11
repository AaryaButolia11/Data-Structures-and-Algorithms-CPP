class Solution
{
public:
    void interleaveQ(queue<int> &q)
    {
        int n = q.size();

        if (n % 2 != 0)
        {
            cout << "Queue size must be even\n";
            return;
        }

        queue<int> firstHalf;

        // Store first half
        for (int i = 0; i < n / 2; i++)
        {
            firstHalf.push(q.front());
            q.pop();
        }

        // Interleave
        while (!firstHalf.empty())
        {
            q.push(firstHalf.front());
            firstHalf.pop();

            q.push(q.front());
            q.pop();
        }
    }
    void rearrangeQueue(queue<int> &q)
    {
        // code here
        interleaveQ(q);
    }
};