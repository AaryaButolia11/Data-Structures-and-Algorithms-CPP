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
};

Node *sortLL(Node *&head)
{
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;

    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;

    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *temp = head;

    while (temp != nullptr)
    {
        Node *nextNode = temp->next; // save next

        if (temp->data == 0)
        {
            zeroTail->next = temp;
            zeroTail = temp;
        }
        else if (temp->data == 1)
        {
            oneTail->next = temp;
            oneTail = temp;
        }
        else
        {
            twoTail->next = temp;
            twoTail = temp;
        }

        temp = nextNode;
    }

    zeroTail->next = (oneHead->next) ? oneHead->next : twoHead->next;
    oneTail->next = twoHead->next;
    twoTail->next = nullptr;

    Node *newHead = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return newHead;
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