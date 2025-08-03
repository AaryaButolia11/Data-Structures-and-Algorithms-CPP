class Solution {
public:
    int powMod(int a, int b, int M) {
        int ans = 1;
        while (b > 0) {
            if (b & 1) {
                ans = (1LL * ans * a) % M;
            }
            a = (1LL * a * a) % M;
            b >>= 1; // Or b = b / 2;
        }
        return ans;
    }
};
