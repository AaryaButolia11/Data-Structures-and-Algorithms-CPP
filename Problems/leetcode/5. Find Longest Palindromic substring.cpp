class Solution {
public:
    bool isPal(string &s, int st,int e)
    {
        while(st<e)
        {
            if(s[st]!=s[e]){
                return false;
            }
            st++,e--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ans="";
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(isPal(s,i,j))
                {
                    string t=s.substr(i,j-i+1);
                    ans=t.size()>ans.size()?t:ans;
                }
            }
        }
        return ans;
    }
};


// this has tc of O(n3) rn, by using DP we can make it O(n2)
