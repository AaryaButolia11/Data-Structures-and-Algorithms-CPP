class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        // code here
        int freqT[256]={0};
        for(int i=0;i<s1.size();i++)
        {
            freqT[s1[i]]++;
        }
        for(int i=0;i<s2.size();i++)
        {
            freqT[s2[i]]--;
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
