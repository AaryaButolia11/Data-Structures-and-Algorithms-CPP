// User function template for C++
bool isPossible(vector<int> arr,int n,int k, int mid) {
    int painter = 1;
    int maxBoard = 0;
    
    for(int i = 0; i<n; i++) {
        if (arr[i] > mid) {
            return false;
        }
        
        if(maxBoard + arr[i] <= mid) {
            maxBoard += arr[i];
        }
        
        else {
            painter++;
            if(painter > k) {
                return false;
            }
            maxBoard = arr[i];
        }
    }
    return true;
}

class Solution {
  public:
    int minTime(vector<int>& arr, int k) {
        int n = arr.size();
        int ans = -1;
        int s = 0;
        int sum = 0;
        
        for(int i = 0; i<n; i++) {
            sum += arr[i];
        }
        
        int end = sum;
        
        while(s<=end) {
            int mid = s + (end - s)/2;
            
           if (isPossible(arr, n, k, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            s = mid + 1;
        }
        }
        return ans;
    }
};
