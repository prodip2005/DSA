#include <iostream>
using namespace std;

int main()
{
    string T, P;
    cout << "Enter Text: ";
    cin >> T;

    cout << "Enter Pattern: ";
    cin >> P;

    int n = T.length();
    int m = P.length();

    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (T[i + j] != P[j])
                break;
        }
        if (j == m)
        {
            cout << "Pattern found at index: " << i;
            return 0;
        }
    }

    cout << "Pattern not found";
    return 0;
}