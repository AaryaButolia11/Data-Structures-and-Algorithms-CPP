// Distinct Permutations of a String
class Solution
{
public:
    set<string> st;
    void printPerm(string &s, int i)
    {
        if (i >= s.length())
        {
            st.insert(s);
            return;
        }

        for (int j = i; j < s.length(); j++)
        {
            swap(s[i], s[j]);
            printPerm(s, i + 1);
            swap(s[i], s[j]);
        }
    }
    vector<string> findPermutation(string &s)
    {
        // Code here there
        int i = 0;
        printPerm(s, i);

        vector<string> res(st.begin(), st.end());
        return res;
    }
};
