class Solution
{
public:
    Node *segregate(Node *head)
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

            Node *nn = temp->next;

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

            temp = nn;
        }

        zeroTail->next = (oneHead->next) ? oneHead->next : twoHead->next;
        oneTail->next = twoHead->next;
        twoTail->next = nullptr;

        Node *ans = zeroHead->next;

        delete zeroHead;
        delete oneHead;
        delete twoHead;

        return ans;
    }
};