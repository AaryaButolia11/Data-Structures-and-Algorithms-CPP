class Solution {
  public:
    int missingNum(vector<int>& arr) {
        int i = 0;
        int n = arr.size();

        while(i < n) {
            int correctIndex = arr[i] - 1;
            // Check bounds and ensure valid swap
            if(arr[i] > 0 && arr[i] <= n && arr[i] != arr[correctIndex]) {
                swap(arr[i], arr[correctIndex]);
            } else {
                i++;
            }
        }

        for(int i = 0; i < n; i++) {
            if(arr[i] != i + 1) {
                return i + 1;
            }
        }

        return n + 1; // If all elements are in place, the missing number is n+1
    }
};
