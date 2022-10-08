#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
#include <sys/time.h>
using namespace std::chrono;
using namespace std;
void print(int arr[], int size);

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Worst Case ::
// Time taken by selection sort: 1803 microseconds
// Time taken by 'linear' insertion sort: 4 microseconds
// Best  Case ::
// Time taken by selection sort: 1479 microseconds
// Time taken by 'linear' insertion sort: 4 microseconds

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
void Linearinsertion(int arr[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int a = arr[i];
        int pos = i;
        int j = i - 1;
        while (j >= 0 && arr[j] > arr[pos])
        {
            swap(arr, pos, j);
            pos--;
            j--;
        }
    }
}
void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int arr[1000];
    for (int i = 1000; i > 0; i--)
        arr[1000 - i] = i;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Worst Case ::" << endl;
    auto start = high_resolution_clock::now();
    selection(arr, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by selection sort: " << duration.count() << " microseconds" << endl;

    auto s = high_resolution_clock::now();
    Linearinsertion(arr, n);
    auto e = high_resolution_clock::now();
    auto d = duration_cast<microseconds>(e - s);
    cout << "Time taken by 'linear' insertion sort: " << d.count() << " microseconds" << endl;

    for (int i = 1; i <= 1000; i++)
        arr[i] = i;

    cout << "Best  Case ::" << endl;
    start = high_resolution_clock::now();
    selection(arr, n);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by selection sort: " << duration.count() << " microseconds" << endl;

    s = high_resolution_clock::now();
    Linearinsertion(arr, n);
    e = high_resolution_clock::now();
    d = duration_cast<microseconds>(e - s);
    cout << "Time taken by 'linear' insertion sort: " << d.count() << " microseconds" << endl;

    return 0;
}