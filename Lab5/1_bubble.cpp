#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void bubbleSort(int arr[], int n)
{
    int count = 1;
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        if (count != 0)
            count = 0;
        else
        {
            cout << "Terminated" << endl;
            break;
        }
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr, j, j + 1);
                count++;
            }
        }
    }
};
void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    cout << "Sorted array:" << endl;
    print(arr, n);
    return 0;
}