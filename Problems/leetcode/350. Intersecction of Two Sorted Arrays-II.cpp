class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> counts;
        vector<int> res;

        for (int num : nums1) {
            counts[num]++;
        }

        for (int num : nums2) {
            if (counts[num] > 0) {
                res.push_back(num);
                counts[num]--;
            }
        }

        return res;
    }
};
