class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        // vector<int> res;

        // for (int x : nums) {

        //     // Handle 0 separately
        //     if (x == 0) {
        //         res.push_back(0);
        //         continue;
        //     }

        //     vector<int> temp;

        //     while (x > 0) {
        //         temp.push_back(x % 10);
        //         x /= 10;
        //     }

        //     reverse(temp.begin(), temp.end());

        //     for (int digit : temp) {
        //         res.push_back(digit);
        //     }
        // }

        // return res;


// better approach as only rev 1 so less SC
        vector<int> res;
        for(int i=nums.size()-1;i>=0;i--){
            int x=nums[i];
            while(x>0){
                res.push_back(x%10);
                x/=10;
            }
        }
        reverse(res.begin(),res.end());

        return res;
    }
};