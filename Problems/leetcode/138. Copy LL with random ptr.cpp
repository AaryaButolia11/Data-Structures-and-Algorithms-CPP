/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    // Node* helperOld(Node* head,unordered_map<Node*,Node*> &mp){
    //     if(head==nullptr) return 0;
    //     Node* nHead=new Node(head->val);
    //     mp[head]=nHead;
    //     nHead->next=helper(head->next,mp);
    //     if(head->random){
    //         nHead->random=mp[head->random];
    //     }
    //     return nHead; //new LL created of new nodes of same replicated values and stored in map
    // }

    Node *helper(Node *head)
    {
        if (!head)
            return 0;
        // sc O(1)
        // step1: to clone the LL
        // old node -> new val
        Node *it = head;
        while (it != nullptr)
        {
            Node *cNode = new Node(it->val);
            cNode->next = it->next;
            it->next = cNode;
            it = it->next->next;
        }

        // step2: assign random ptr of A to A'
        it = head;
        while (it != nullptr)
        {
            Node *cNode = it->next;
            cNode->random = it->random ? it->random->next : nullptr;
            it = it->next->next;
        }

        // step 3: detach A' and A
        it = head;
        Node *cHead = it->next;
        while (it)
        {
            Node *cNode = it->next;
            it->next = it->next->next;
            if (cNode->next)
            {
                cNode->next = cNode->next->next;
            }
            it = it->next;
        }
        return cHead;
    }
    Node *copyRandomList(Node *head)
    {
        // unordered_map<Node*,Node*> mp;
        // new node mapping stored in this

        return helper(head);
    }
};