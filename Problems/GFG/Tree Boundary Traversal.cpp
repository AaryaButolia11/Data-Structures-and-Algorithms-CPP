/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution
{
public:
    bool isLeaf(Node *root)
    {
        if (root->left == nullptr && root->right == nullptr)
            return true;
        return false;
    }
    void addLB(Node *root, vector<int> &res)
    {
        Node *curr = root->left;
        while (curr)
        {
            if (!isLeaf(curr))
                res.push_back(curr->data);
            if (curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }
    void addRB(Node *root, vector<int> &res)
    {
        Node *curr = root->right;
        vector<int> temp;
        while (curr)
        {
            if (!isLeaf(curr))
                temp.push_back(curr->data);
            if (curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }
        reverse(temp.begin(), temp.end());
        for (auto it : temp)
        {
            res.push_back(it);
        }
    }

    void addL(Node *root, vector<int> &res)
    {
        if (isLeaf(root))
        {
            res.push_back(root->data);
            return;
        }
        if (root->left)
            addL(root->left, res);
        if (root->right)
            addL(root->right, res);
    }

    vector<int> boundaryTraversal(Node *root)
    {
        // code here
        vector<int> res;
        if (!root)
            return res;
        if (!isLeaf(root))
            res.push_back(root->data);
        addLB(root, res);
        addL(root, res);
        addRB(root, res);
        return res;
    }
};