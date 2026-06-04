#include <stack>
#include <iostream>
using namespace std;
class Nstack
{
    int *a, *top, *next;
    int n;        // no of stacks
    int s;        // size of mainarray
    int freespot; // tells free space in main array
public:
    Nstack(int _n, int _s) : n(_n), s(_s)
    {
        a = new int[s];
        top = new int[n];
        next = new int[s];
        // initially all stacks are empty and all spaces in main array are free
        for (int i = 0; i < n; i++)
            top[i] = -1;
        // next is used to maintain free spaces in main array
        for (int i = 0; i < s - 1; i++)
            next[i] = i + 1;
        // last element of next is -1 to indicate end of free list
        next[s - 1] = -1;
        freespot = 0;
    }
    bool push(int x, int m)
    {
        // check for overflow
        if (freespot == -1)
            return false;
        // 1. find index at which to insert element
        int index = freespot;
        // update freespot to next free position
        freespot = next[index];
        // 2. insert element in array
        a[index] = x;
        // 3. update next to point to previous top of stack
        next[index] = top[m - 1];
        // 4. update top to point to new top of stack
        top[m - 1] = index;
        return true;
    }

    // pop from mth stack and return popped element
    int pop(int m)
    {
        // check for underflow
        if (top[m - 1] == -1)
            return -1;
        // 1. find index of top element in stack m
        int index = top[m - 1];
        // 2. update top to point to next element in stack m
        top[m - 1] = next[index];
        // 3. add the freed index to the free list
        next[index] = freespot;
        freespot = index;
        // return the popped element
        return a[index];
    }

    ~Nstack()
    {
        delete[] a;
        delete[] top;
        delete[] next;
    }
};
int main()
{
    Nstack s(3, 6);
    s.push(1, 1);
    s.push(1, 1);
    s.push(1, 1);
    s.push(2, 1);
    s.push(3, 2);
    s.push(4, 3);
    s.push(5, 2);
    cout << s.pop(1) << endl; // Output: 2
    cout << s.pop(1) << endl; // Output: 1
    return 0;
}