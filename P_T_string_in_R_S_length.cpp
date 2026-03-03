#include <iostream>
#include <cstring>
using namespace std;

int findPattern(char T[], char P[], int s, int r)
{
    for (int i = 0; i <= s - r; i++)
    {
        int j = 0;

        while (j < r && T[i + j] == P[j])
            j++;

        if (j == r)
            return i;
    }
    return -1;
}

int main()
{
    char T[100], P[100];
    int s, r;

    cout << "Enter text: ";
    cin >> T;

    cout << "Enter pattern: ";
    cin >> P;

    s = strlen(T);
    r = strlen(P);

    int index = findPattern(T, P, s, r);

    if (index != -1)
        cout << "Pattern found at index: " << index;
    else
        cout << "Pattern not found";

    return 0;
}