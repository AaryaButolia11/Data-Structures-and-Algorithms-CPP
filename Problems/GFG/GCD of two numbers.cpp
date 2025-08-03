class Solution {
  public:
    int gcd(int max, int min) {
        // code here
        if(max==0) return min;
        if(min==0) return max;
        while(max>0 && min>0)
        {
            if(max>min)
            {
                max=max-min;
            }
            else{
                min=min-max;
            }
        }
        return max==0?min:max;
    }
};
