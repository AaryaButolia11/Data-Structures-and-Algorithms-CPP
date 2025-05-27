
class Solution {
  public:
    int seriesSum(int n) {
        // code here
        if(n==0)
        {
            return 0;

        }
        int sum=n+seriesSum(n-1);
        
        return sum;
    }
};
