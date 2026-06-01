class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // ListNode* dummy = new ListNode(0);
        // ListNode* cur = dummy;

        // while (list1 && list2) {
        //     if (list1->val > list2->val) {
        //         cur->next = list2;
        //         list2 = list2->next;
        //     } else {
        //         cur->next = list1;
        //         list1 = list1->next;
        //     }
        //     cur = cur->next;
        // }

        // cur->next = list1 ? list1 : list2;

        // ListNode* head = dummy->next;
        // delete dummy;
        // return head;
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;
        while (list1 && list2)
        {
            if (list1->val > list2->val)
            {
                curr->next = list2;
                list2 = list2->next;
            }
            else
            {
                curr->next = list1;
                list1 = list1->next;
            }
            curr = curr->next;
        }
        while (list1 != nullptr)
        {
            curr->next = list1;
            list1 = list1->next;
            curr = curr->next;
        }
        while (list2 != nullptr)
        {
            curr->next = list2;
            list2 = list2->next;
            curr = curr->next;
        }
        return dummy->next;
    }
};