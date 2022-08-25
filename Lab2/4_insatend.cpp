#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;
void insatend(int arr[], int e, int s)
{
    int narr[s + 1];
    narr[s] = e;

    for (int i = 0; i < s; i++)
        narr[i] = arr[i];
    for (int i = 0; i < s + 1; i++)
        cout << narr[i] << " ";
}
int main()
{

    int arr[] = {5, 2, 10, 1, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    insatend(arr, 1, n);
    return 0;
}
