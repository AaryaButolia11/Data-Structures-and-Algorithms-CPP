#include <iostream>
using namespace std;
class Stack
{

public:
    // to locate addr of the stack
    int *arr;

    // to locate top of the stack
    int top;

    // to store size of the stack
    int size;

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    // function
    void push(int data)
    {
        // to check for storage
        if (top == size - 1)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        top++;
        arr[top] = data;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow" << endl;
            return;
        }
        int topEle = arr[top];
        top--;
        // return topEle;
    }

    int getTop()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }
    int getSize()
    {
        // this tells total no.of ele present in stack
        return top + 1;
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

int main()
{
    Stack s(10);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << "size of stack is " << s.getSize() << endl;

    while (!s.isEmpty())
    {
        cout << s.getTop() << endl;
        s.pop();
    }

    cout << "size of stack is " << s.getSize() << endl;

    return 0;
}