class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int i = 0;
        int n = arr.size();

        // Cyclic sort
        while(i < n) {
            int correctIndex = arr[i] - 1;
            if(arr[i] != arr[correctIndex]) {
                swap(arr[i], arr[correctIndex]);
            } else {
                i++;
            }
        }

        // Find the repeating and missing elements
        for(int i = 0; i < n; i++) {
            if(arr[i] != i + 1) {
                // arr[i] is repeating, i+1 is missing
                return {arr[i], i + 1};
            }
        }

        return {-1, -1}; // Just in case something goes wrong
    }
};
