// TC-O(ROWS*COLNS)
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size(); //n*n matrix
        long long sum=0;
        int countNeg=0;
        int smallestVal=INT_MAX;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                sum+=abs(matrix[i][j]);
                if(matrix[i][j]<0)
                {
                    countNeg++;
                }
                smallestVal=min(smallestVal,abs(matrix[i][j]));
            }
        }
        if(countNeg%2==0){
            return sum;
        }
        return sum-2*smallestVal;
    }
};
