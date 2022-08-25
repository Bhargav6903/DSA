#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;
void delet(int arr[], int p, int s)
{

    for (int i = p; i < s; i++)
        arr[i - 1] = arr[i];

    for (int i = 0; i < s - 1; i++)
        cout << arr[i] << " ";
}
int main()
{

    int arr[] = {5, 2, 10, 1, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    delet(arr, 1, n);
    return 0;
}
