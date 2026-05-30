class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {

        ListNode *temp = head;
        for (int i = 0; i < k; i++)
        {
            if (temp == nullptr)
                return head; // less than k nodes
            temp = temp->next;
        }

        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *forward = nullptr;

        int cnt = 0;

        while (cnt < k)
        {
            // forward as curr's next
            forward = curr->next;
            // curr next to be prev (null init)
            curr->next = prev;
            // upd prev to be curr
            prev = curr;
            // upd curr to be forward
            curr = forward;
            cnt++;
        }
        // set head -> next to be reversed result of LL by recurrsion
        head->next = reverseKGroup(curr, k);

        // return new head of LL ie prev
        return prev;
    }
};