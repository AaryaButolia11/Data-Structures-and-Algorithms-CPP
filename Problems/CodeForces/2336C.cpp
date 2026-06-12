#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long a, b, x;
        cin >> a >> b >> x;

        queue<pair<long long, long long>> q;
        map<pair<long long, long long>, int> dist;

        q.push({a, b});
        dist[{a, b}] = 0;

        while (!q.empty())
        {
            pair<long long, long long> curr = q.front();
            q.pop();

            long long u = curr.first;
            long long v = curr.second;

            int steps = dist[curr];

            if (u == v)
            {
                cout << steps << "\n";
                break;
            }

            pair<long long, long long> p1 = {u + 1, v};
            pair<long long, long long> p2 = {u, v + 1};
            pair<long long, long long> p3 = {u / x, v};
            pair<long long, long long> p4 = {u, v / x};

            if (!dist.count(p1))
            {
                dist[p1] = steps + 1;
                q.push(p1);
            }

            if (!dist.count(p2))
            {
                dist[p2] = steps + 1;
                q.push(p2);
            }

            if (!dist.count(p3))
            {
                dist[p3] = steps + 1;
                q.push(p3);
            }

            if (!dist.count(p4))
            {
                dist[p4] = steps + 1;
                q.push(p4);
            }
        }
    }

    return 0;
}