class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {

        if (head == nullptr || head->next == nullptr)
            return nullptr;

        ListNode *slow = head;
        ListNode *fast = head;

        // Find meeting point inside cycle (if cycle exists)
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                break;
            }
        }

        // No cycle found
        if (fast == nullptr || fast->next == nullptr)
            return nullptr;

        // Move slow to head
        slow = head;

        // Move both one step at a time
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        // Start of cycle
        return slow;
    }
};