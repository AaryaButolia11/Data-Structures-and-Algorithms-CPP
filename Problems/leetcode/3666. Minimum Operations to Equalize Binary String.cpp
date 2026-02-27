/*
============================================================
Problem: Minimum Operations on Binary String
============================================================

Problem Summary:
Given a binary string `s` of length `n` and an integer `k`,
we need to determine the minimum number of operations required
to make the string valid under given constraints.

Key Observations:
- Count the number of '0's in the string.
- Let:
    zero = number of '0's
    one  = n - zero
- If there are no zeros → already valid → return 0.
- If n == k:
    - Only possible configurations depend on whether all
      characters are same or not.

Core Idea:
We divide the string conceptually into:
    k sized block
    (n - k) sized block

Let:
    base = n - k

We compute two possible answers:
1) odd case  → answer must be odd
2) even case → answer must be even

For each case, we compute the minimum number of operations
required to balance zeros in both partitions.

We use ceiling division:
    ceil(a / b) = (a + b - 1) / b

Then:
    odd  = max( ceil(zero/k), ceil((n-zero)/base) )
    even = max( ceil(zero/k), ceil(zero/base) )

We adjust:
    - odd must be odd
    - even must be even

Parity Constraints:
- If k % 2 == zero % 2 → odd case valid
- If zero is even → even case valid

We take minimum valid result.
If no configuration valid → return -1.

============================================================
Time Complexity:
------------------------------------------------------------
O(n)
- Single pass to count zeros
- All other operations are O(1)

Space Complexity:
------------------------------------------------------------
O(1)
- Only integer variables used

============================================================
Bit Trick Used:
------------------------------------------------------------
~s[i] & 1
This efficiently checks if character is '0'
because:
    '0' -> ASCII 48 (even)
    '1' -> ASCII 49 (odd)

============================================================
*/