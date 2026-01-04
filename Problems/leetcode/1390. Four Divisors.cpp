// Learning: Divisors come in pair.
// TC-o(n*√nums)

class Solution {
public:
    int findSumDiv(int num)
    {
        int div=0;//count
        int sum=0;//sum of div.
        for(int fact=1;fact*fact<=num;fact++)
        {
            if(num%fact==0)
            {
                int other=(num/fact);
                if(other==fact) //case of a perfect sq num.
                {
                    div+=1;
                    sum+=fact;
                }
                else{
                    div+=2;
                    sum+=(fact+other);
                }
            }
            if(div>4)
            {
                return 0;
            }
        }
        return div==4?sum:0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int res=0;
        for(int &num:nums)
        {
            res+=findSumDiv(num);
        }
        return res;
    }
};

