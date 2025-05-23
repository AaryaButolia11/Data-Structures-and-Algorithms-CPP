class Solution {
  public:
    int firstRepeated(vector<int> &a) {
        // sol1
        // int n=a.size();

        // for(int i=0;i<n;i++)
        // {
        //     bool isRep = false;
        //     for(int j=i+1;j<n;j++)
        //     {
        //         if(a[i]==a[j])
        //         {
        //             isRep=true;
        //             return i+1;
        //         }
        //     }
        // }
        // return -1;
        
        // hashing
        unordered_map<int,int>hash;
        for(int i=0;i<a.size();i++)
        {
            hash[a[i]]++;
        }
        
        for(int i=0;i<a.size();i++)
        {
            if(hash[a[i]]>1)
            {
                return i+1;
            }
        }
        return -1;
        
    }
};
