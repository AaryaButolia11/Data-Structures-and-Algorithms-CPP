class MyStack
{
public:
    queue<int> q;

    MyStack()
    {
    }

    void push(int x)
    {
        q.push(x);

        int n = q.size();
        for (int i = 0; i < n - 1; i++)
        {
            int topEle = q.front();
            q.pop();
            q.push(topEle);
        }
    }

    int pop()
    {
        int top = q.front();
        q.pop();
        return top;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};