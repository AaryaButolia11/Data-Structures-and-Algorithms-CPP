#include <iostream>
#include <queue>
using namespace std;

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

int main()
{
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);

    interleaveQ(q);

    cout << "Printing Queue:\n";

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}