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
bool detectLoop(Node *&head)
{
    if (head == nullptr)
    {
        cout << "LL is empty" << endl;
        return false;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr)
    {
        fast = fast->next;
        if (fast != nullptr)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    Node *sixth = new Node(60);
    Node *seventh = new Node(70);
    Node *eighth = new Node(80);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = third; // creating a loop

    if (detectLoop(head))
    {
        cout << "Loop detected" << endl;
    }
    else
    {
        cout << "No loop detected" << endl;
    }

    return 0;
}