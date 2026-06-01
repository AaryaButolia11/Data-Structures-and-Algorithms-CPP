/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *a = headA;
        ListNode *b = headB;
        while (a->next != nullptr && b->next != nullptr)
        {
            if (a == b)
                return a;
            a = a->next;
            b = b->next;
        }

        if (a->next == 0 && b->next == 0 && a != b)
            return 0;
        if (a->next == nullptr)
        {
            // b is larger
            // how much big?
            int blen = 0;
            while (b->next != nullptr)
            {
                blen++;
                b = b->next;
            }
            while (blen--)
            {
                headB = headB->next;
            }
        }
        else
        {
            // a is longer
            int alen = 0;
            while (a->next != nullptr)
            {
                alen++;
                a = a->next;
            }
            while (alen--)
            {
                headA = headA->next;
            }
        }
        while (headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }
        return headB;
    }
}; 