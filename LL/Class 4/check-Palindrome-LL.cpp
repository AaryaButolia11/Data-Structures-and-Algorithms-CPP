#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
};

Node *reverseLL(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *prev = nullptr;
    Node *curr = head;
    Node *forward = head->next;
    while (curr != nullptr)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

bool checkPalindrome(Node *head)
{
    // case when linked list is empty or has only one node, then it is a palindrome
    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    // finding middle of the linked list
    Node *slow = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    // now slow is at the middle of the linked list

    // reverse the second half of the linked list
    Node *revLL = reverseLL(slow->next);
    slow->next = revLL;

    // start comparing the first half and the reversed second half of the linked list
    Node *temp = head;
    Node *temp2 = revLL;
    while (temp2 != nullptr)
    {
        if (temp->data != temp2->data)
        {
            return false;
        }
        temp = temp->next;
        temp2 = temp2->next;
    }
    return true;
}
int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(2);
    Node *fifth = new Node(1);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;
    bool isPalin = checkPalindrome(head);
    if (isPalin)
    {
        cout << "The linked list is a palindrome." << endl;
    }
    else
    {
        cout << "The linked list is not a palindrome." << endl;
    }
    return 0;
}