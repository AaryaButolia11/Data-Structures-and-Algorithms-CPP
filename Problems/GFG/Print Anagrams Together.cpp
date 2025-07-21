// User function Template for C++

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& strs) {
        // code here
        map<string, vector<string> >mp;
        for(auto str:strs)
        {
            string s=str;
            sort(s.begin(),s.end());
            mp[s].push_back(str);

        } 

        vector<vector<string>> ans;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            ans.push_back(it->second);
        }

        return ans;
    }
};
