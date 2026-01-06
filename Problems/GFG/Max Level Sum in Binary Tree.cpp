/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

class Solution {
  public:
    /*You are required to complete below method */
    int maxLevelSum(Node* root) {
        // Your code here
        int maxSum=INT_MIN;
        int resLvl=0;
        queue<Node*> que;
        que.push(root);
        int currLvl=1;
        while(!que.empty())
        {
            int n=que.size();
            int sum=0;
            while(n--)
            {
                Node* temp=que.front();
                que.pop();
                sum+=temp->data;
                if(temp->left){
                    que.push(temp->left);
                }
                if(temp->right){
                    que.push(temp->right);
                }
            }
            if (sum>maxSum){
                maxSum=sum;
                resLvl=currLvl;
            }
            currLvl++;
        }
        return maxSum;
    }
};
