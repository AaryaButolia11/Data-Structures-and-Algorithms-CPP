class Solution {
public:
    void sortColors(vector<int>& nums) {

      // soln1
        // sort(nums.begin(),nums.end());

      // soln2
        // count methods
        // int zeros, ones,twos;
        // zeros=ones=twos=0;
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(nums[i]==0)
        //     {
        //         zeros++;
        //     }
        //     else if(nums[i]==1)
        //     {
        //         ones++;
        //     }
        //     else{
        //         twos++;
        //     }
        // }
        // int i=0;
        // while(zeros--){
        //     nums[i]=0;
        //     i++;
        // }
        // while(ones--){
        //     nums[i]=1;
        //     i++;
        // }
        // while(twos--){
        //     nums[i]=2;
        //     i++;
        // }

      // soln3
        int l=0;
        int m=0;
        int h=nums.size()-1;
        while(m<=h)
        {
            if(nums[m]==0)
            {
                swap(nums[l],nums[m]);
                m++;
                l++;

            }
            else if(nums[m]==1){
                m++;
            }
            else{
                // for 2
                swap(nums[h],nums[m]);
                h--;
            }
        }

    }
};
