class Solution {
  public:
    bool arraySortedOrNot(vector<int>& arr) {
        // code here
        int n=arr.size();
        int count=0;
        for(int i=1;i<n;i++)
        {
            if(arr[i-1]>arr[i])
            {
                count++;
            }
        }
        
        if(arr[n-1]>arr[0])
        {
            count++;
        }
        
        return count<=1;
    }
};
