#include <iostream>
using namespace std;

int main() {
    int P, Q, X, Y;
    cin >> P >> Q >> X >> Y;

    if (P <= X && X <= P + 99 && Q <= Y && Y <= Q + 99)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
