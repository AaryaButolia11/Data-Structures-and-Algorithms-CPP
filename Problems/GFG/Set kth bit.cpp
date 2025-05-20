class Solution {
  public:
    int setKthBit(int n, int k) {
        // Step 1: Create a bitmask with only the k-th bit set
        // For example, if k = 3 => mask = 00001000 (1 shifted 3 positions to the left)
        int mask = 1 << k;

        // Step 2: Use bitwise OR to set the k-th bit of n
        // n | mask ensures the k-th bit becomes 1, regardless of its original value
        int ans = n | mask;

        // Step 3: Return the result
        return ans;
    }
};

/*
Flow Explanation:
-----------------
Given: 
    - Integer `n` (the number whose bit is to be modified)
    - Integer `k` (the bit position to be set, 0-indexed from the right)

Objective: 
    - Set the k-th bit of `n` to 1 (even if it's already 1)

Steps:
1. Create a bitmask by shifting `1` to the left by `k` positions.
   For example, if k = 2 → mask = 00000100 (binary for 4)

2. Perform bitwise OR between `n` and the mask:
   - If the k-th bit in `n` is 0 → it becomes 1
   - If the k-th bit in `n` is already 1 → it stays 1

3. Return the modified value of `n`

Example:
---------
n = 5 (binary: 00000101), k = 1
mask = 00000010
n | mask = 00000111 → 7
Result = 7
*/
