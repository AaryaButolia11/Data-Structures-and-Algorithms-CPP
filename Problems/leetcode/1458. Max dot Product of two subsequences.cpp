class Solution {
public:
    int m,n;
    int t[501][501];
    int solve(vector<int>& nums1, vector<int>& nums2, int i,int j){
        if(i==m||j==n) return -1e9;

        if(t[i][j]!=-1e9) return t[i][j];

        int val=nums1[i]*nums2[j];
        int takeij=(nums1[i]*nums2[j])+solve(nums1,nums2,i+1,j+1);
        int takei=solve(nums1,nums2,i,j+1);
        int takej=solve(nums1,nums2,i+1,j);
        return t[i][j]=max({val,takeij,takei,takej});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        m=nums1.size();
        n=nums2.size();
        for(int i=0;i<501;i++)
        {
            for(int j=0;j<501;j++){
                t[i][j]=-1e9;
            }
        }
        return solve(nums1,nums2,0,0);
    }
};

// t[i][j] is used to **store the result of the subproblem starting at indices i and j to avoid recomputation — this technique is called memoization.`
/*
Approach: Dynamic Programming (Memoization)

t[i][j] stores the maximum dot product possible using
subarrays nums1[i..] and nums2[j..].

We try four choices:
1) Take current pair (i, j)
2) Take current pair and move both pointers
3) Skip element from nums2
4) Skip element from nums1

Memoization avoids recomputation of overlapping subproblems,
reducing time complexity to O(m * n).

Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/
