class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // unordered_set<int> res;
        // vector<int> ans;
        // for(int i=0;i<nums1.size();i++)
        // {
        //     for(int j=0;j<nums2.size();j++)
        //     {
        //         if(nums1[i]==nums2[j])
        //         {
        //             res.insert(nums1[i]);
        //         }
        //     }
        // }
        // for(auto i:res)
        // {
        //     ans.push_back(i);
        // }

        // return ans;
        unordered_set<int> set1(nums1.begin(), nums1.end());  // Store all nums1 elements
        unordered_set<int> res;  // To store intersection without duplicates
        
        for (int num : nums2) {
            if (set1.find(num) != set1.end()) {  // If num in nums1
                res.insert(num);  // Add to result set
            }
        }
        
        // Convert set to vector
        return vector<int>(res.begin(), res.end());
    }
};
