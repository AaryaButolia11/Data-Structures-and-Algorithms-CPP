class Solution {
  public:
    // Function to find common elements in three arrays.
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2,
                               vector<int> &arr3) {
        vector<int> ans;
        set<int> set;
        
        int i,j,k;
        i=j=k=0;
        while(i<arr1.size() && j<arr2.size() && k<arr3.size())
        {
            if(arr1[i]==arr2[j] && arr2[j]==arr3[k])
            {
                // cout<<arr1[i]<<" ";
                // ans.push_back(arr1[i]);
                set.insert(arr1[i]);
                i++;j++;k++;

            }
            else if(arr1[i]<arr2[j])
            {
                i++;
            }
            else if(arr2[j]<arr3[k])
            {
                j++;
            }
            else{
                k++;
            }
        }
        
        for(auto i:set)
        {
            ans.push_back(i);
        }
        return ans;
        
        
    }
};
