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
    int getLen(ListNode *head)
    {
        int l = 0;
        ListNode *temp = head;
        while (temp != nullptr)
        {
            l++;
            temp = temp->next;
        }
        return l;
    }
    ListNode *sortList(ListNode *head)
    {
        int lenLL = getLen(head);
        vector<int> sortLL;
        ListNode *temp = head;
        while (temp != nullptr)
        {
            sortLL.push_back(temp->val);
            temp = temp->next;
        }
        sort(sortLL.begin(), sortLL.end());
        temp = head;
        for (auto i : sortLL)
        {
            temp->val = i;
            temp = temp->next;
        }

        return head;
    }
};