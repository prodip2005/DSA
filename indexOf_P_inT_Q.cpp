#include <iostream>
using namespace std;

int main()
{
    string T, P, Q;

    cout << "Enter Text: ";
    cin >> T;

    cout << "Enter Pattern (P): ";
    cin >> P;

    cout << "Enter Replace String (Q): ";
    cin >> Q;

    int pos = 0;

    while ((pos = T.find(P, pos)) != string::npos)
    {
        T.replace(pos, P.length(), Q);
        pos += Q.length();
    }

    cout << "Updated Text: " << T;

    return 0;
}