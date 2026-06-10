#include <iostream>
using namespace std;

// Deque (Double Ended Queue)
// In a deque, insertion and deletion can be performed
// from both FRONT and REAR ends.
class Deque
{
public:
    int *arr;  // Dynamic array to store deque elements
    int size;  // Maximum size of deque
    int front; // Points to front element
    int rear;  // Points to rear element

    // Constructor
    Deque(int s)
    {
        this->size = s;

        // Dynamically allocate memory for array
        arr = new int[size];

        // When deque is empty, both front and rear are -1
        front = rear = -1;
    }

    // Insert element from REAR side
    void pushRear(int x)
    {
        // Queue Full Condition
        // In circular queue, if next position of rear
        // becomes front, then queue is full.
        if ((rear + 1) % size == front)
        {
            cout << "Queue is Full\n";
            return;
        }

        // First element insertion
        if (front == -1)
        {
            front = rear = 0;
            arr[rear] = x;
        }

        // Normal insertion or circular movement
        else
        {
            // Move rear circularly
            rear = (rear + 1) % size;

            // Insert element
            arr[rear] = x;
        }
    }

    // Insert element from FRONT side
    void pushFront(int x)
    {
        // Full condition
        // Front at first index and rear at last index
        // means no space left.
        if (front == 0 && rear == size - 1)
        {
            cout << "Full";
            return;
        }

        // First element insertion
        else if (front == -1)
        {
            front = rear = 0;
        }

        // If front reaches beginning of array,
        // move it to last position (circular move)
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
        }

        // Normal movement towards left
        else
        {
            front--;
        }

        // Insert element at front position
        arr[front] = x;
    }

    // Delete element from FRONT side
    void popFront()
    {
        // Empty deque
        if (front == -1)
        {
            cout << "Queue is Empty!";
            return;
        }

        // Only one element exists
        else if (front == rear)
        {
            arr[front] = -1;

            // Reset deque
            front = -1;
            rear = -1;
        }

        // Circular condition:
        // If front reaches last index,
        // move it to first index.
        else if (front == size - 1)
        {
            front = 0;
        }

        // Normal movement
        else
        {
            front++;
        }
    }

    // Delete element from REAR side
    void popRear()
    {
        // Empty deque
        if (front == -1)
        {
            cout << "Queue is Empty!";
            return;
        }

        // Only one element exists
        else if (front == rear)
        {
            arr[front] = -1;

            // Reset deque
            front = -1;
            rear = -1;
        }

        // Circular condition:
        // If rear is at index 0,
        // move it to last index.
        else if (rear == 0)
        {
            rear = size - 1;
        }

        // Normal movement
        else
        {
            rear--;
        }
    }
};

int main()
{
    return 0;
}