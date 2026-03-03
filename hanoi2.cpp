#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    long long moves = pow(2, n) - 1;

    cout << "Total moves: " << moves;

    return 0;
}