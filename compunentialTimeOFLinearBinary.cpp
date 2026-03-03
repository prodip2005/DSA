#include <iostream>
#include <ctime>
using namespace std;

int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

int binarySearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int n, key;
    cout << "Enter size: ";
    cin >> n;

    int arr[100000];

    cout << "Enter sorted elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter key: ";
    cin >> key;

    clock_t start, end;

    start = clock();
    linearSearch(arr, n, key);
    end = clock();
    cout << "Linear Search Time: "
         << double(end - start) / CLOCKS_PER_SEC << " sec\n";

    start = clock();
    binarySearch(arr, n, key);
    end = clock();
    cout << "Binary Search Time: "
         << double(end - start) / CLOCKS_PER_SEC << " sec\n";

    return 0;
}