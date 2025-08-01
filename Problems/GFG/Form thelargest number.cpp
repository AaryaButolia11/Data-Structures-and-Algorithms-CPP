class Solution {
  public:
    static bool comp(string a,string b)
    {
        string t1=a+b;
        string t2=b+a;
        return t1>t2;
    }
    string findLargest(vector<int> &nums) {
        // code here
        vector<string> snums;
        for(auto n:nums){
            snums.push_back(to_string(n));
        }
        sort(snums.begin(),snums.end(),comp);
        if(snums[0]=="0") return "0";
        string ans="";
        for(auto str:snums)
        {
            ans+=str;
        }
        return ans;
    }
};
