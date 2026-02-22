#include <iostream>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    bool taken[101] = {0};

    for (int i = 0; i < N; i++)
    {
        int L, x, chosen = 0;
        cin >> L;

        for (int j = 0; j < L; j++)
        {
            cin >> x;
            if (!taken[x] && chosen == 0)
            {
                chosen = x;
                taken[x] = 1;
            }
        }

        cout << chosen << endl;
    }
}