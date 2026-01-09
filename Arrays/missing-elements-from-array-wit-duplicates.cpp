#include <iostream>
using namespace std;
void find_missing(int *a, int n)
{
    // visited method
    for (int i = 0; i < n; i++)
    {
        int index = abs(a[i]);
        if (a[index - 1] > 0)
        {
            a[index - 1] *= -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {

            cout << i + 1 << " ";
        }
    }
}

void sort_swap(int *a, int n)
{
    int i = 0;
    while (i < n)
    {
        int index = a[i] - 1;
        if (a[i] != a[index])
        {
            swap(a[i], a[index]);
        }
        else
        {
            i++;
        }
    }
    for (int i = 0; i < n; i++)
    {

        if (a[i] != i + 1)
        {
            cout << i + 1 << " ";
            // cout << a[i] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n;
    int a[] = {1, 5, 3, 3, 4};
    n = sizeof(a) / sizeof(int);
    // find_missing(a, n);
    sort_swap(a, n);
    return 0;
}