class Solution {
public:
    long long coloredCells(int n) {
        long long count=1;
        long long jump=4;
        while(n>1)
        {
            count=count+jump;
            jump=jump+4;
            n--;
        }
        return count;
    }
};
