#include <iostream>
#include <stack>
using namespace std;

// Function to insert an element at the bottom of the stack
void insertAtBottom(stack<int> &st, int x)
{
    // Base case: If stack is empty, insert the element
    if (st.empty())
    {
        st.push(x);
        return;
    }

    // Store the top element and remove it
    int topEle = st.top();
    st.pop();

    // Recursively reach the bottom of the stack
    insertAtBottom(st, x);

    // Put back the removed element
    st.push(topEle);
}

// Function to reverse the stack using recursion
void revStack(stack<int> &st)
{
    // Base case: Empty stack is already reversed
    if (st.empty())
        return;

    // Store and remove the top element
    int topEle = st.top();
    st.pop();

    // Recursively reverse the remaining stack
    revStack(st);

    // Insert the removed element at the bottom
    // This effectively reverses the order
    insertAtBottom(st, topEle);
}

int main()
{
    stack<int> st;

    // Push elements into the stack
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    // Reverse the stack
    revStack(st);

    // Print the reversed stack
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}