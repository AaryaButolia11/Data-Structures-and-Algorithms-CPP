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
    ListNode *findMid(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast != 0)
        {
            fast = fast->next;
            if (fast != 0)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }
    ListNode *merge(ListNode *list1, ListNode *list2)
    {
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
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        // break LL into two halves using mid by slow-fast.
        ListNode *mid = findMid(head);
        ListNode *left = head;
        ListNode *right = mid->next;
        mid->next = nullptr; // by this we crete 2 seperate lists
        // sort RE
        left = sortList(left);
        right = sortList(right);

        // merge both
        ListNode *mergedLL = merge(left, right);
        return mergedLL;
    }
};