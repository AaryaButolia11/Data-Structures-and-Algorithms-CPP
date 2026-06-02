/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    int getLen(ListNode *&head)
    {
        ListNode *temp = head;
        int l = 0;
        while (temp != nullptr)
        {
            l++;
            temp = temp->next;
        }
        return l;
    }
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head)
            return 0;
        int len = getLen(head);
        int actualRotateK = (k % len);
        if (actualRotateK == 0)
            return head;
        int newLastNodePos = len - actualRotateK - 1;
        ListNode *newLastNode = head;
        for (int i = 0; i < newLastNodePos; i++)
        {
            newLastNode = newLastNode->next;
        }
        ListNode *newHead = newLastNode->next;
        newLastNode->next = nullptr;
        ListNode *it = newHead;
        while (it->next)
            it = it->next;
        it->next = head;
        return newHead;
    }
};
