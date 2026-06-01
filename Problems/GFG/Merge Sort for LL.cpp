/*
class Node {
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution
{
public:
    Node *findMid(Node *head)
    {
        Node *slow = head;
        Node *fast = head->next;

        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }

    Node *merge(Node *left, Node *right)
    {
        Node dummy(-1);
        Node *tail = &dummy;

        while (left && right)
        {
            if (left->data <= right->data)
            {
                tail->next = left;
                left = left->next;
            }
            else
            {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }

        if (left)
            tail->next = left;
        else
            tail->next = right;

        return dummy.next;
    }

    Node *mergeSort(Node *head)
    {
        // Base case
        if (head == NULL || head->next == NULL)
            return head;

        // Find middle
        Node *mid = findMid(head);

        // Split into two halves
        Node *left = head;
        Node *right = mid->next;
        mid->next = NULL;

        // Recursive sorting
        left = mergeSort(left);
        right = mergeSort(right);

        // Merge sorted halves
        return merge(left, right);
    }
}; 