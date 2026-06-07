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
class Solution
{
public:
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        unordered_map<int, TreeNode *> mp; // map storing parent val and its tree node addr
        unordered_set<int> childSet;       // child set to include all nodes that cant be parent

        for (vector<int> &v : descriptions)
        {
            // find parameters
            int parent = v[0];
            int child = v[1];
            int isLeft = v[2];

            // create parent node if not in map rn
            if (mp.find(parent) == mp.end())
            {
                mp[parent] = new TreeNode(parent);
            }

            // create child nodes
            if (mp.find(child) == mp.end())
            {
                mp[child] = new TreeNode(child);
            }

            // check for left child
            if (isLeft == 1)
            {
                // left child is 1
                mp[parent]->left = mp[child];
            }
            else
            {
                mp[parent]->right = mp[child]; // right child
            }

            // if child add as it cant be parent in future
            childSet.insert(child);
        }

        // find the root of tree
        for (vector<int> v : descriptions)
        {
            int parent = v[0];
            // if node not in the childset then its the parent
            if (childSet.find(parent) == childSet.end())
            {
                // return node which is not listed in set as its not child of anyone
                return mp[parent];
            }
        }
        return NULL;
    }
};