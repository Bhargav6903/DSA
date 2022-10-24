#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;

void insert(int a[], int M, int p, int value)
{
    int i = 0, home = value % M;
    int hp = 1 + value % p;
    while (a[(home + i * hp) % M] != 0)
        i++;
    a[(home + i * hp) % M] = value;
}
void printarray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

bool search(int a[], int m, int p, int value)
{
    int home = value % m;
    int hp = 1 + value % p;
    int i = 0;
    while (a[(home + i * hp) % m] != 0)
    {
        if (a[(home + i * hp) % m] == value)
            return true;
        i++;
    }
    return false;
}

void contain(int arr[], int M, int p, int value)
{
    if (search(arr, M, p, value))
        cout << "True" << endl;
    else
        cout << "False" << endl;
}
int main()
{
    int M = 13, p = 8;
    int arr[M] = {0};
    vector<int> v = {765, 431, 96, 142, 579, 226, 903, 388};
    for (int i = 0; i < v.size(); i++)
        insert(arr, M, p, v[i]);
    printarray(arr, M);
    contain(arr, M, p, 105);
    contain(arr, M, p, 150);
    contain(arr, M, p, 174);
}