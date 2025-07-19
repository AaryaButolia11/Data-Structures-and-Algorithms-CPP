class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // if(s==t)
        // {
        //     return true;
        // }

        // return false;

        int freqT[256]={0};
        for(int i=0;i<s.size();i++)
        {
            freqT[s[i]]++;
        }
        for(int i=0;i<t.size();i++)
        {
            freqT[t[i]]--;
        }

        for(int i=0;i<256;i++)
        {
            if(freqT[i]!=0)
            {
                return false;
            }
        }
        return true;
    }
};
