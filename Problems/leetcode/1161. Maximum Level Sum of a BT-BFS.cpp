/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


//  using BFS
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxSum=INT_MIN;
        int resLvl=0;
        
        // queue for BFS
        queue<TreeNode*> que;
        que.push(root); //insert the root elem
        int currLvl=1;  //inc the level to 1 as root is already added
        while(!que.empty()){
            int n=que.size(); //for each level
            int sum=0;
            while(n--){
                TreeNode* temp=que.front();
                que.pop();
                sum+=temp->val;
                if(temp->left){ //check if it has any left child
                    que.push(temp->left);
                }
                if(temp->right){ //check if it has any right child
                    que.push(temp->right);
                }
            }
            if(sum>maxSum) //update if found greate value
            {
                maxSum=sum;
                resLvl=currLvl;
            }
            currLvl++; //inc curr level to go to next lvl
        }
        return resLvl; 
    }
};
