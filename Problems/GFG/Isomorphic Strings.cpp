class Solution {
  public:
    bool areIsomorphic(string &s, string &t) {
        // code here
        int hash[256]={0};
        int isTCharsMapped[256]={0};
        for(int i=0;i<s.size();i++)
        {
            if(hash[s[i]]==0 && isTCharsMapped[t[i]]==0)
            {
                hash[s[i]]=t[i];
                isTCharsMapped[t[i]]=true;
            }
        }

        for(int i=0;i<s.size();i++)
        {
            if(char(hash[s[i]])!=t[i])
            {
                return false;
            }
        }
        return true;
    }
};
