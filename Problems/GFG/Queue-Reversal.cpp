class Solution
{
public:
    void revQ(queue<int> &q)
    {
        if (q.empty())
        {
            return;
        }

        int ele = q.front();
        q.pop();
        revQ(q);
        q.push(ele);
    }
    void reverseQueue(queue<int> &q)
    {
        // code here
        revQ(q);
    }
};