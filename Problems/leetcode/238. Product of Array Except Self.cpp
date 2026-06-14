class Solution
{
public:
    // calc preffix
    vector<int> prefixProd(vector<int> &nums)
    {
        int n = nums.size();
        int pref = 1;
        // prefix starting as 1 to multiply
        vector<int> temp(n);

        temp[0] = 1;

        // loop from 1 as we req prev ele ie at 0 by starting with 0 we catn get -1
        for (int i = 1; i < n; i++)
        {
            // calc pref by mult curr to prev no
            pref = pref * nums[i - 1];
            // upd in arr
            temp[i] = pref;
        }
        return temp;
    }

    vector<int> suffixProd(vector<int> &nums)
    {
        int n = nums.size();
        int suff = 1;
        vector<int> temp(n);
        // suff of last ele is 1
        temp[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            // calc suffix from n-2 to 0
            // n-2 as we know suffix of n-1 but by n we wont get n+1 suffix
            suff = suff * nums[i + 1];
            // upd in arr
            temp[i] = suff;
        }
        return temp;
    }

    // find prefix and suffix of all ele in the array and the product of whole array except them will be the product of pref and suff
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> p = prefixProd(nums);
        vector<int> s = suffixProd(nums);

        for (int i = 0; i < n; i++)
        {
            nums[i] = p[i] * s[i];
        }

        return nums;
    }
};