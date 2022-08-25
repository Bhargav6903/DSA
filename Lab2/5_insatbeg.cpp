#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;
void insatbeg(int arr[], int e, int s)
{
    int narr[s + 1];
    narr[0] = e;

    for (int i = 1; i < s + 1; i++)
        narr[i] = arr[i - 1];
    for (int i = 0; i < s + 1; i++)
        cout << narr[i] << " ";
}
int main()
{

    int arr[] = {5, 2, 10, 1, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    insatbeg(arr, 1, n);
    return 0;
}
