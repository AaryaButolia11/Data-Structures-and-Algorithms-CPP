class Solution {
  public:
    pair<int, int> getMinMax(vector<int> arr) {
        int min = INT_MAX;
        int max = INT_MIN;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] < min) {
                min = arr[i];  // directly assign the new min
            }
            if(arr[i] > max) {
                max = arr[i];  // directly assign the new max
            }
        }
        return {min, max};
    }
};
