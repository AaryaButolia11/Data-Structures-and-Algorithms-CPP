class Solution {
public:
    int expandAtIdx(string s,int left,int right)
    {
        int count=0;
        while(left>=0 && right<s.length() && s[left]==s[right])
        {
            count++;
            left--;
            right++;
        }

        return count;
    }
    int countSubstrings(string s) {
        int count=0;
        int n=s.length();

        for(int center=0;center<n;center++)
        {
            // odd
            int oddCount = expandAtIdx(s,center,center);
            count+=oddCount;

            // even
            int evenCount = expandAtIdx(s,center,center+1);
            count+=evenCount;
        }
        return count;
    }
};
