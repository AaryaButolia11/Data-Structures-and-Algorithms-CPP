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
    bool hasCycle(ListNode *head)
    {

        // Initialize slow and fast pointers at the head
        ListNode *slow = head;
        ListNode *fast = head;

        // Traverse until fast reaches the end of the list
        while (fast != nullptr && fast->next != nullptr)
        {

            // Move slow pointer by 1 step
            slow = slow->next;

            // Move fast pointer by 2 steps
            fast = fast->next->next;

            // If both pointers meet, a cycle exists
            if (slow == fast)
            {
                return true;
            }
        }

        // Fast reached NULL, so no cycle exists
        return false;
    }
};