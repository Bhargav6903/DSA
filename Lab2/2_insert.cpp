#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;
void insert(int arr[], int p, int e, int s)
{
    int narr[s + 1];
    for (int i = 0; i < p - 1; i++)
        narr[i] = arr[i];
    narr[p - 1] = e;
    for (int i = p; i <= s; i++)
        narr[i] = arr[i - 1];
    for (int i = 0; i < s + 1; i++)
        cout << narr[i] << " ";
}
int main()
{

    int arr[] = {5, 2, 10, 1, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    insert(arr, 1, 1, n);
    return 0;
}
