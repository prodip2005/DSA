#include <iostream>
#include <stack>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    stack<int> st;
    st.push(low);
    st.push(high);

    while (!st.empty())
    {
        high = st.top();
        st.pop();
        low = st.top();
        st.pop();

        int pi = partition(arr, low, high);

        if (pi - 1 > low)
        {
            st.push(low);
            st.push(pi - 1);
        }

        if (pi + 1 < high)
        {
            st.push(pi + 1);
            st.push(high);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[100];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}