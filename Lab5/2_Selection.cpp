#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;
using namespace std::chrono;
void print(int arr[], int size);
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void selection(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(arr, min, i);
    }
};
void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int arr[] = {10, 1, 9, 8, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    selection(arr, n);
    printf("Sorted array: \n");
    print(arr, n);

    return 0;
}