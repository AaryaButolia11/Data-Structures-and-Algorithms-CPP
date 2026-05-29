using namespace std;
#include <iostream>

// DLL - Doubly Linked List Class
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int value)
    {
        data = value;
        prev = nullptr;
        next = nullptr;
    }

    Node()
    {
        data = 0;
        prev = nullptr;
        next = nullptr;
    }

    ~Node()
    {
        cout << "Node with value " << data << " is being deleted" << endl;
    }
};

// print DLL o(n)
void prnDLL(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// get length of DLL o(n)
int getLength(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// insertion at head o(1)
void insertAtHead(Node *&head, Node *&tail, int val)
{
    if (head == nullptr)
    {
        head = new Node(val);
        tail = head;
        return;
    }
    Node *nn = new Node(val);
    nn->next = head;
    head->prev = nn;
    head = nn;
    return;
}

// insertion at tail o(1)
void insertAtTail(Node *&head, Node *&tail, int val)
{
    if (tail == nullptr)
    {
        head = new Node(val);
        tail = head;
        return;
    }
    Node *nn = new Node(val);
    tail->next = nn;
    nn->prev = tail;
    tail = nn;
    return;
}

// insertion at any position o(n)
void insertAtPosition(Node *&head, Node *&tail, int pos, int val)
{
    if (head == nullptr)
    {
        head = new Node(val);
        tail = head;
        return;
    }
    else if (pos == 1)
    {
        insertAtHead(head, tail, val);
        return;
    }
    int len = getLength(head);
    if (pos == len + 1)
    {
        insertAtTail(head, tail, val);
        return;
    }
    Node *prevNode = head;
    for (int i = 1; i < pos - 1; i++)
    {
        prevNode = prevNode->next;
    }
    Node *nn = new Node(val);
    nn->next = prevNode->next;
    prevNode->next->prev = nn;
    prevNode->next = nn;
    nn->prev = prevNode;
}

void delFromPosn(Node *&head, Node *&tail, int pos)
{
    if (head == nullptr)
    {
        cout << "DLL is empty" << endl;
        return;
    }
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        head->prev = nullptr;
        temp->next = nullptr;
        delete temp;
        return;
    }
    int len = getLength(head);
    if (pos > len)
    {
        cout << "Invalid position" << endl;
        return;
    }
    if (pos == len)
    {
        Node *temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        temp->prev = nullptr;
        delete temp;
        return;
    }

    // deletion in middle
    Node *leftNode = head;
    for (int i = 1; i < pos - 1; i++)
    {
        leftNode = leftNode->next;
    }
    Node *curr = leftNode->next;
    Node *rightNode = curr->next;

    leftNode->next = rightNode;
    rightNode->prev = leftNode;
    curr->next = nullptr;
    curr->prev = nullptr;
    delete curr;
}
int main()
{

    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);

    first->next = second;
    second->prev = first;
    second->next = third;
    third->prev = second;

    prnDLL(first);
    insertAtHead(first, third, 5);
    prnDLL(first);

    cout << endl;

    prnDLL(first);
    insertAtTail(first, third, 100);
    prnDLL(first);

    cout << endl;

    prnDLL(first);
    insertAtPosition(first, third, 2, 105);
    prnDLL(first);

    cout << endl;
    delFromPosn(first, third, 2);
    prnDLL(first);
    return 0;
}