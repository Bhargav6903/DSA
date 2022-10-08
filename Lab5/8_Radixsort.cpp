#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;
void print(int arr[], int size);
void Radixsort(int arr[], int len, int n)
{
    vector<int> v[10];
    for (int i = 0; i < len; i++)
    {
        int p = pow(10, i);
        for (int j = 0; j < n; j++)
        {
            int a = ((arr[j] / p)) % 10;

            v[a].push_back(arr[j]);
        }

        int count = 0;
        for (int k = 0; k < 10; k++)
        {
            if (v[k].size() == 0)
                continue;
            for (int j = 0; j < v[k].size(); j++)
            {
                arr[count] = v[k][j];
                count++;
            }
            v[k].clear();
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
    int arr[] = {237, 146, 259, 348, 152, 163, 235, 48, 36, 690};
    int n = sizeof(arr) / sizeof(arr[0]);
    Radixsort(arr, 3, n);
    print(arr, n);
}