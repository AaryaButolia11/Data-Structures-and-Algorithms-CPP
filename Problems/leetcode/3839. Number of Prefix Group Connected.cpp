class Solution
{
public:
    int prefixConnected(vector<string> &words, int k)
    {
        int ans = 0;
        unordered_map<string, int> pfCount;
        for (const string &word : words)
        {
            if (word.length() >= k)
            {
                string prefix = word.substr(0, k);
                pfCount[prefix]++;
            }
        }

        for (const auto &e : pfCount)
        {
            if (e.second >= 2)
            {
                ans++;
            }
        }
        return ans;
    }
};