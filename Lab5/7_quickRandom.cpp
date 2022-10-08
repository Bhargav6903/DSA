#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;
void print(int arr[], int size);
int findpivot(int arr[], int left, int right);

int random(int high, int low)
{
    srand(time(0));
    return (low + rand() % high);
}
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
    int pivot = arr[random(high, low)];
    cout << pivot << ' ' << low << " " << high << endl;
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

        for (int i = 0; i < 6; i++)
            cout << arr[i] << " ";
        cout << endl;
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
    int arr[] = {3, 4, 12, 30, 121, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    print(arr, n);
    return 0;
}