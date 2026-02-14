#include <iostream>
#include <vector>
using namespace std;
int main()
{

    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++)
        cin >> S[i];
    int max_len = 0;
    for (auto &x : S)
        max_len = max(max_len, (int)x.size());
    for (int i = 0; i < N; i++)
    {
        int len = S[i].size();
        int pad = (max_len - len) / 2;
        cout << string(pad, '.') << S[i] << string(pad, '.') << endl;
    }

    return 0;
}