#include <iostream>
#include <queue>
using namespace std;

int main()
{

    int T;
    cin >> T;

    while (T--)
    {

        int N, D;
        cin >> N >> D;

        queue<pair<int, int>> q;
        // (purchase_day, eggs)

        for (int i = 1; i <= N; i++)
        {

            int A, B;
            cin >> A >> B;

            // Morning: buy eggs
            q.push({i, A});

            // Noon: use eggs
            int need = B;

            while (need > 0)
            {

                auto &front = q.front();

                if (front.second <= need)
                {

                    need -= front.second;
                    q.pop();
                }
                else
                {

                    front.second -= need;
                    need = 0;
                }
            }

            // Evening: discard expired eggs
            while (!q.empty() && q.front().first <= i - D + 1)
            {

                q.pop();
            }
        }

        long long total = 0;

        while (!q.empty())
        {

            total += q.front().second;
            q.pop();
        }

        cout << total << endl;
    }
}