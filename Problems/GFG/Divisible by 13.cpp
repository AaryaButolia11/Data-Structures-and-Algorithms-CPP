class Solution {
  public:
    bool divby13(string &s) {
        // code here
        int rem = 0;
        for(char c: s){
            int digit=c-'0';
            rem = (rem * 10 + digit) % 13;

        }
        return (rem==0);
    }
};
