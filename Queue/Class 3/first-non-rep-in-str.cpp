#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // input
    string s = "aabc";
    int freq[26] = {0};
    int n = s.size();
    queue<char> q;
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        // inc freq
        freq[ch - 'a']++;
        // push ele
        q.push(ch);

        while (!q.empty())
        {
            if (freq[q.front() - 'a'] > 1)
            {
                q.pop();
            }
            else
            {
                ans.push_back(q.front());
                break;
            }
        }
        if (q.empty())
        {
            ans.push_back('#');
        }
    }
    cout << ans;
     return 0;
}