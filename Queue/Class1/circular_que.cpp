#include <iostream>
using namespace std;
class CircularQueue
{
public:
    int *arr; // array to store queue elements
    int size;
    int front;
    int rear;
    CircularQueue(int s)
    {
        this->size = s;
        arr = new int[size];
        // both front and rear are -1 when queue is empty
        front = rear = -1;
    }

    void push(int x)
    {
        // Queue Full
        if ((rear + 1) % size == front)
        {
            cout << "Queue is Full\n";
            return;
        }

        // First element
        if (front == -1)
        {
            front = rear = 0;
            arr[rear] = x;
        }

        // Circular movement
        else
        {
            rear = (rear + 1) % size;
            arr[rear] = x;
        }
    }

    void pop()
    {
        //  empty
        if (front == -1)
        {
            cout << "Queue is Empty!";
        }
        // single ele del
        else if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        // circular nature
        else if (front == size - 1)
        {
            front = 0;
        }
        // normal
        {
            front++;
        }
    }
};
int main()
{
    return 0;
}