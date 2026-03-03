#include <iostream>
using namespace std;

int main()
{
    int n, key;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter value to search: ";
    cin >> key;

    int position = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            position = i;
            break;
        }
    }

    if (position != -1)
        cout << "Element found at index: " << position;
    else
        cout << "Element not found";

    return 0;
}