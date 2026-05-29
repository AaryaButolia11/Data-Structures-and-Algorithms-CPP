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

void delNode(int pos, Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "LL is empty" << endl;
        return;
    }
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    int len = findLength(head);
    if (pos == len)
    {
        // find prev
        int i = 1;
        Node *prev = head;
        while (i < pos - 1)
        {
            prev = prev->next;
            i++;
        }
        // prev -> next = null
        prev->next = NULL;
        // temp = tail
        Node *temp = tail;
        // tail = prev
        tail = prev;
        // del temp
        delete temp;
        return;
    }

    // delete in middle
    int i = 1;
    Node *prev = head;
    for (i = 1; i < pos - 1; i++)
    {
        prev = prev->next;
    }
    Node *curr = prev->next;
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
    return;
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
    delNode(1, head, tail);

    prntLL(head);

    return 0;
}