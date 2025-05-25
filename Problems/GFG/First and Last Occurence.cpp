class Solution {
  public:
    vector<int> find(vector<int>& arr, int x) {
        int size = arr.size();
        vector<int> res{-1, -1};
        
        // Find the leftmost index (first occurrence)
        res[0] = binarySearch(arr, size, x, true);
        
        // Find the rightmost index (last occurrence)
        res[1] = binarySearch(arr, size, x, false);
        
        return res;
    }
    
    int binarySearch(vector<int>& arr, int size, int target, bool findFirst) {
        int start = 0;
        int end = size - 1;
        int result = -1;
        
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(arr[mid] == target) {
                result = mid;
                
                // For leftmost, move towards the left
                // For rightmost, move towards the right
                if(findFirst) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else if(arr[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        return result;
    }
};
