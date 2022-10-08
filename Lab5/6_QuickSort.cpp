#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;
void print(int arr[], int size);

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void quicksort(int arr[], int low, int high)
{
    if (high - low <= 0)
        return;

    int i = low, j = high;
    int pivot = arr[(low + high) / 2];
    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            swap(arr, i, j);
            i++;
            j--;
        }
    }
    quicksort(arr, low, j);
    quicksort(arr, i, high);
}

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    // int arr[] = {5, 4, 3, 2, 1};
    int arr[] = {10, 2, 9, 15, 7, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    print(arr, n);
    return 0;
}