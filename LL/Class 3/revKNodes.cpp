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

Node *revKNode(Node *head, int k)
{
    if (head == NULL)
    {
        cout << "LL is empty" << endl;
        return NULL;
    }
    int l = getLen(head);
    if (k > l)
    {
        cout << "k is greater than length of LL" << endl;
        return head;
    }
    // rev first k nodes
    Node *prev = NULL;
    Node *curr = head;
    Node *next = curr->next;
    int cnt = 0;
    while (cnt < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    if (next != NULL)
    {
        head->next = revKNode(next, k);
    }
    return prev;
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
    int k = 3;
    head = revKNode(head, k);
    print(head);

    return 0;
}