#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;
void printtable(vector<int> v[], int m);
bool contain(vector<int> c, int value);
void insert(vector<int> v[], vector<int> c, int M, int value)
{
    int i = 0;
    while (contain(c, (value + i) % M))
        i++;
    int home = (value + i) % M;
    v[home].push_back(value);
}
void Firstinsert(vector<int> v[], int M, int value)
{
    int home = (value) % M;
    v[home].push_back(value);
}
bool contain(vector<int> c, int value)
{
    for (int i = 0; i < c.size(); i++)
        if (c[i] == value)
            return true;
    return false;
}
void reassignment(vector<int> arr[], vector<int> c, int v)
{
    for (int i = 0; i < arr[v].size(); i++)
    {
        int a = arr[v][arr[v].size() - i - 1];
        insert(arr, c, 13, a);
    }
    int a = arr[v].size();
    for (int i = 0; i < a; i++)
        arr[v].pop_back();
}
void printtable(vector<int> v[], int M)
{
    for (int i = 0; i < M; i++)
    {
        if (v[i].size() == 0)
        {
            cout << 0 << endl;
            continue;
        }
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int M = 17;
    vector<int> arr[M];
    vector<int> v1 = {1, 2, 3, 4}; // In v1 vector you can add which 4 servers you want to crash.
    for (int i = 1; i < 127; i++)
        Firstinsert(arr, M, i);

    for (int i = 0; i < 4; i++)
        reassignment(arr, v1, v1[i]);
    printtable(arr, M);
}