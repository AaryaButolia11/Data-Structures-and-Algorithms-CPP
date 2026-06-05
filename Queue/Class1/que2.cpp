#include <iostream>
#include <queue>
using namespace std;
class Queue
{
public:
    int *arr; // array to store queue elements
    int size;
    int front;
    int rear;

    Queue(int s)
    {
        this->size = s;
        arr = new int[size];
        front = rear = 0;
    }

    void push(int data)
    {
        // queue is full checl
        if (rear == size)
        {
            cout << "Queue is full!!" << endl;
            return;
        }
        else // or else insert
        {
            arr[rear] = data;
            rear++;
        }
    }

    void pop()
    {
        // check if queue is empty
        if (front == rear)
        {
            cout << "Queue is empty!!" << endl;
            return;
        }
        else
        {
            arr[front] = -1; // mark deleted element as -1
            front++;
            if (front == rear) // reset queue if all elements are deleted
            {
                front = rear = 0;
            }
        }
    }

    int getFront()
    {
        if (front == rear)
        {
            cout << "Queue is empty!!" << endl;
            return -1; // return -1 to indicate empty queue
        }
        else
        {
            return arr[front];
        }
    }

    int size()
    {
        return rear - front; // number of elements in the queue
    }

    bool isEmpty()
    {
        // true if empty, false otherwise
        return front == rear;
    }
};
int main()
{
    Queue q(5); // create a queue of size 5
    q.push(10);
    q.push(20);
    q.push(30);
    cout << "Front element: " << q.getFront() << endl; // should print 10
    q.pop();
    cout << "Front element after pop: " << q.getFront() << endl;        // should print 20
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl; // should print No
    q.pop();
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl; // should print Yes
    return 0;
}