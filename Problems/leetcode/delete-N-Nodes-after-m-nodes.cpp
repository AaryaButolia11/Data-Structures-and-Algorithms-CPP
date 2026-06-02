#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
    ~Node() { cout << "Node with value " << data << " is being deleted." << endl; }
};

void delLL(Node *&head, int m, int n)
{
    // Empty list
    if (head == nullptr)
        return;

    // If m = 0, delete the entire list
    if (m == 0)
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        return;
    }

    // Pointer used to traverse the list
    Node *curr = head;

    while (curr)
    {
        // =========================
        // Step 1: Keep m nodes
        // =========================
        // Move curr to the m-th node
        for (int i = 1; i < m && curr; i++)
        {
            curr = curr->next;
        }

        // If we reached the end, nothing more to delete
        if (curr == nullptr)
            return;

        // =========================
        // Step 2: Delete next n nodes
        // =========================
        // temp points to first node to be deleted
        Node *temp = curr->next;

        for (int i = 0; i < n && temp; i++)
        {
            // Store next node before deleting current one
            Node *nextNode = temp->next;

            // Delete current node
            delete temp;

            // Move to next node to be deleted
            temp = nextNode;
        }

        // =========================
        // Step 3: Connect the kept
        // part with remaining list
        // =========================
        curr->next = temp;

        // Continue from the next surviving node
        curr = temp;
    }
}
int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = nullptr;
    int m = 2, n = 2;
    delLL(head, m, n);
    cout << "Remaining list: ";
    Node *it = head;
    while (it)
    {
        cout << it->data << " ";
        it = it->next;
    }
    return 0;
}