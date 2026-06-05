using namespace std;
#include <iostream>
#include <queue>
int main()
{
    // creation
    queue<int> q;

    q.push(5);
    q.push(10);
    q.push(15);
    q.push(25);

    // size
    cout << "Size of queue: " << q.size() << endl;

    // pop ele
    cout << "Del 1 ele!" << endl;

    q.pop();

    // size
    cout << "Size of queue: " << q.size() << endl;

    // check empty
    if (q.empty())
        cout << "Q is empty!!";
    else
        cout << "q isnt empty!";

    // check for front ele
    cout << "\nFront ele: " << q.front() << endl;

    // check for back ele
    cout << "Back ele: " << q.back() << endl;
    return 0;
}