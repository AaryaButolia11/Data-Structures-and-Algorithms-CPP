#include <iostream>
#include <vector>
using namespace std;

void findChar(string &str, int &n, int i, char &key, vector<int> &ans)
{
    if (i >= n)
    {
        return;
    }
    if (str[i] == key)
    {
        ans.push_back(i);
    }
    findChar(str, n, i + 1, key, ans); // Removed 'return' keyword
}

int main()
{
    string str = "lovebabbar";
    int n = str.length();
    char key = 'b';
    int i = 0;

    vector<int> ans;
    findChar(str, n, i, key, ans);

    cout << "Character '" << key << "' found at indices:" << endl;
    for (auto val : ans)
    {
        cout << val << " ";
    }
    cout << endl;

    if (ans.empty())
    {
        cout << "Character not found!" << endl;
    }
    else
    {
        cout << "Total occurrences: " << ans.size() << endl;
    }

    return 0;
}