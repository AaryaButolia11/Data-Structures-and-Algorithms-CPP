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

Node *removeDuplicatesLLUnsorted(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    map<int, bool> visited;

    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL)
    {
        if (visited[curr->data])
        {
            prev->next = curr->next;

            Node *temp = curr;
            curr = curr->next; // move before deleting

            delete temp;
        }
        else
        {
            visited[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(2);

    head->next = second;
    second->next = third;
    third->next = fourth;

    head = removeDuplicatesLLUnsorted(head);

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
