#include <iostream>
#include <vector>
using namespace std;

void print_subarr_util(vector<int> &s, int start, int end)
{
    if (end == s.size())
    {
        return;
    }
    for (int i = start; i < end; i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;
    print_subarr_util(s, start, end + 1);
}
void print_subarr(vector<int> &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        print_subarr_util(s, i, i + 1);
    }
}

int main()
{
    vector<int> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.push_back(x);
    }

    print_subarr(s);

    return 0;
}

// TC - WORST CASE - O(N2)
// SC - O(N) - AUXILIARY STACK SPACE