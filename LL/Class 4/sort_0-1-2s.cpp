#include <iostream>
#include <map>
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
};

int getLen(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
Node *sortLL(Node *&head)
{
    int zero = 0;
    int ones = 0;
    int twos = 0;
    if (head == NULL)
    {
        return head;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zero++;
        }
        else if (temp->data == 1)
        {
            ones++;
        }
        else
        {
            twos++;
        }
        temp = temp->next;
    }

    temp = head;
    while (temp != nullptr)
    {
        // fill 0s
        while (zero--)
        {
            temp->data = 0;
            temp = temp->next;
        }
        // fill 1s
        while (ones--)
        {
            temp->data = 1;
            temp = temp->next;
        }
        // fill 2s
        while (twos--)
        {
            temp->data = 2;
            temp = temp->next;
        }
    }
    return head;
}
int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(1);
    Node *fourth = new Node(1);
    Node *fifth = new Node(0);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    Node *res = sortLL(head);
    while (res != NULL)
    {
        cout << res->data << " ";
        res = res->next;
    }
    return 0;
}