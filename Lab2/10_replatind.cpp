#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;
void replatind(int arr[], int p, int e, int s)
{
    if (p <= s)
    {
        arr[p - 1] = e;
        for (int i = 0; i < s; i++)
            cout << arr[i] << " ";
    }
    else
        cout << -1;
}
int main()
{

    int arr[] = {5, 2, 10, 1, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    replatind(arr, 4, 8, n);
    return 0;
}
