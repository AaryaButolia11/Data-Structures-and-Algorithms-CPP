#include <unordered_map>

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        unordered_map<int, int> mp;

        // Count frequencies
        ListNode *temp = head;
        while (temp)
        {
            mp[temp->val]++;
            temp = temp->next;
        }

        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;

        temp = head;

        while (temp)
        {
            if (mp[temp->val] == 1)
            {
                tail->next = temp;
                tail = tail->next;
            }
            temp = temp->next;
        }

        tail->next = nullptr; // terminate the new list

        return dummy->next;
    }
};

// approach 2: without using extra space
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *prev = dummy;
        ListNode *curr = head;

        while (curr)
        {

            // Check if current node is the start of duplicates
            if (curr->next && curr->val == curr->next->val)
            {

                int duplicateVal = curr->val;

                // Skip all nodes having this value
                while (curr && curr->val == duplicateVal)
                {
                    curr = curr->next;
                }

                prev->next = curr;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};