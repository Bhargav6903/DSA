#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;

void insert(int a[], int M, int value)
{
    int i = 0, home = value;
    while (a[(home + i * i) % M] != 0)
        i++;
    a[(home + i * i) % M] = value;
}
void printarray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

bool search(int a[], int m, int value)
{
    int home = value;
    int i = 0;
    while (a[(home + i * i) % m] != 0)
    {
        if (a[(home + i * i) % m] == value)
            return true;
        i++;
    }
    return false;
}

void contain(int arr[], int M, int value)
{
    if (search(arr, M, value))
        cout << "True" << endl;
    else
        cout << "False" << endl;
}
int main()
{
    int M = 17;
    int arr[M] = {0};
    insert(arr, M, 133);
    insert(arr, M, 88);
    insert(arr, M, 150);
    insert(arr, M, 92);
    insert(arr, M, 221);
    insert(arr, M, 174);
    insert(arr, M, 88);
    insert(arr, M, 105);

    printarray(arr, M);
    contain(arr, M, 105);
    contain(arr, M, 150);
    contain(arr, M, 174);
    cout << "------------------------------------" << endl;
    int M1 = 37;
    int arr1[M1] = {0};
    vector<int> v = {133, 150, 151, 187, 88, 250, 170, 134, 135, 207};
    for (int i = 0; i < v.size(); i++)
        insert(arr1, M1, v[i]);

    printarray(arr1, M1);
    contain(arr1, M1, 105);
    contain(arr1, M1, 150);
    contain(arr1, M1, 174);
}