#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void prntLL(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);

    // empty LL
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *nn = new Node(data);

    // empty LL
    if (tail == NULL)
    {
        head = nn;
        tail = nn;
    }
    else
    {
        tail->next = nn;
        tail = nn;
    }
}

int findLength(Node *&head)
{
    Node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void insertAtPosition(Node *&head, Node *&tail, int data, int pos)
{
    // insert at beginning
    if (pos == 0)
    {
        insertAtHead(head, tail, data);
        return;
    }

    int len = findLength(head);

    // insert at end
    if (pos >= len)
    {
        insertAtTail(head, tail, data);
        return;
    }

    Node *nn = new Node(data);

    Node *prev = head;

    for (int i = 0; i < pos - 1; i++)
    {
        prev = prev->next;
    }

    nn->next = prev->next;
    prev->next = nn;
}

int main()
{
    Node *head = new Node(10);

    // tail should point to same node
    Node *tail = head;

    insertAtHead(head, tail, 5);
    insertAtHead(head, tail, 15);

    insertAtTail(head, tail, 20);

    prntLL(head);

    insertAtPosition(head, tail, 25, 3);
    insertAtPosition(head, tail, 30, 1);
    insertAtPosition(head, tail, 40, 0);

    prntLL(head);

    return 0;
}