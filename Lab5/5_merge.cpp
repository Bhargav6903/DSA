#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;

void print(int arr[], int size);
void merge1(int a[], int left, int mid, int right);
void mergesort(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergesort(a, left, mid);
        mergesort(a, mid + 1, right);
        merge1(a, left, mid, right);
    }
}
void merge1(int a[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    vector<int> b;
    while (i <= mid && j <= right)
    {
        if (a[i] < a[j])
        {
            b.push_back(a[i]);
            i++;
        }
        else
        {
            b.push_back(a[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        b.push_back(a[i]);
        i++;
    }
    while (j <= right)
    {
        b.push_back(a[j]);
        j++;
    }

    for (int i = left; i - left < b.size(); i++)
        a[i] = b[i - left];
}
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

    mergesort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    print(arr, n);

    return 0;
}