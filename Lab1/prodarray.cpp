#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;

int addarray(int arr[], int n)
{
    if (n == 0)
        return 1;
    else
        return arr[n - 1] * addarray(arr, n - 1);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << addarray(arr, n);
}
