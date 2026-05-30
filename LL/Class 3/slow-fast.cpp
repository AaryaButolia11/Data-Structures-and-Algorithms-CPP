#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
};

Node *getMid(Node *head)
{
    if (head == NULL)
    {
        cout << "LL is empty" << endl;
        return head;
    }
    if (head->next == NULL)
    {
        return head;
    }

    // LL has more than 1 node
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // slow is pointing to the middle node
    return slow;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    Node *sixth = new Node(60);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;

    print(head);

    cout << "Mid node is: " << getMid(head)->data << endl;
    return 0;
}