#include <iostream>
using namespace std;
void printNum(int num)
{
    if (num == 0)
    {
        return;
    }
    int lastDigit = num % 10;
    printNum(num / 10);
    {
        cout << lastDigit;
    }
}
int main()
{
    int num = 647;
    printNum(num);
    return 0;
} 