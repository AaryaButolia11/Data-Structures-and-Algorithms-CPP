#include <iostream>
#include <deque>
using namespace std;

int main()
{
    // Creation
    deque<int> dq;

    dq.push_front(5);
    dq.push_front(10);
    dq.push_back(20);
    dq.push_back(30);

    // Current deque: 10 5 20 30

    dq.pop_front(); // removes 10
    dq.pop_back();  // removes 30

    // Deque becomes: 5 20

    cout << "Size: " << dq.size() << endl;

    cout << "Ele at front: " << dq.front() << endl;
    cout << "Ele at back: " << dq.back() << endl;

    return 0;
}