#include <iostream>
using namespace std;

void hanoi(int n, int start, int end)
{
    if (n == 1)
    {
        cout << start << " -> " << end << endl;
        return;
    }

    int other = 6 - (start + end);

    hanoi(n - 1, start, other);

    cout << start << " -> " << end << endl;

    hanoi(n - 1, other, end);
}

int main()
{
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    hanoi(n, 1, 3);

    return 0;
}