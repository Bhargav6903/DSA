#include <iostream>
using namespace std;

void buildHeap(int arr[], int n, int i)
{
    int ind = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] < arr[ind])
    {
        ind = l;
    }

    if (r < n && arr[r] < arr[ind])
    {
        ind = r;
    }

    if (ind != i)
    {

        swap(arr[i], arr[ind]);

        buildHeap(arr, n, ind);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        buildHeap(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        buildHeap(arr, i, 0);
    }
}

int main()
{
    cout << "Enter the length of the array:";
    int n;
    cin >> n;
    cout << "Enter array elements in proper sequence seperated by space:";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    heapSort(arr, n);

    cout << "\nArray in increasing order:";
    for (int i = n - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }

    cout << "\nArray in decreasing order:";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}