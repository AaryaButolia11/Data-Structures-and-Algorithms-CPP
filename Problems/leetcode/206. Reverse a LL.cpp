class Solution
{
public:
    // recurrsion
    // ListNode* revL(ListNode* prev,ListNode* curr){
    //     if(curr==nullptr) return prev;
    //     ListNode* frwd=curr->next;
    //     curr->next=prev;
    //     return revL(curr,frwd);
    // }
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* prev = NULL;
    //     ListNode* curr = head;
    //     return revL(prev,curr);
    // }
    ListNode *reverseList(ListNode *head)
    {
        ListNode *current = head;
        ListNode *prev = nullptr;
        while (current != nullptr)
        {
            ListNode *newNode = current->next;
            current->next = prev;
            // moving prev
            prev = current;
            // moving current to next node
            current = newNode;
        }
        return prev;
    }
};