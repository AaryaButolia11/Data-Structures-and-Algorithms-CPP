#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> horses; //{time,index}
    for (int i = 1; i <= N; i++)
    {
        int t;
        cin >> t;
        horses.push_back({t, i});
    }
    sort(horses.begin(), horses.end());
    cout << horses[0].second << " ";
    cout<< horses[1].second << " ";
    cout<< horses[2].second << "\n";
    return 0;
}