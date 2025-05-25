class Solution {
public:

    int findPeak(vector<int>& arr)
    {
        int s=0;
        int e=arr.size()-1;
        while(s<e)
        {
            int mid=(s+e)/2;
            if(arr[mid]<arr[mid+1])
            {
                s=mid+1;

            }
            else{
                e=mid;
            }
        }
        return s;

    }
    int peakIndexInMountainArray(vector<int>& arr) {
        int ans= findPeak(arr);
        return ans;

    }
};
