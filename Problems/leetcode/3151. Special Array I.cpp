#include <vector>

class Solution {
public:
    bool isOdd(int x) {
        return (x % 2 != 0);
    }

    bool isArraySpecial(std::vector<int>& nums) {
        if (nums.size() <= 1) {
            return true;
        }

        for (int i = 1; i < nums.size(); ++i) {
            if (isOdd(nums[i]) == isOdd(nums[i-1])) {
                return false;
            }
        }
        return true;
    }
};
