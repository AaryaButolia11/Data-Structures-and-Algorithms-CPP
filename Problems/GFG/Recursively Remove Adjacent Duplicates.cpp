// User function template for C++

class Solution {
  public:
    string removeUtil(string s) {
    bool changed;
    do {
        changed = false;
        string temp;
        for (int i = 0; i < s.size(); ) {
            if (i < s.size() - 1 && s[i] == s[i+1]) {
                // Skip adjacent duplicates
                char current = s[i];
                while (i < s.size() && s[i] == current) i++;
                changed = true;
            } else {
                temp.push_back(s[i]);
                i++;
            }
        }
        s = temp;
    } while (changed);
    return s;
}
};
