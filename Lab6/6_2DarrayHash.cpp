#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;
void printtable(vector<int> v[], int m);
void insert(vector<int> v[], int M, int value)
{
    int home = value % M;
    v[home].push_back(value);
    // printtable(v, M);
}
bool search(vector<int> v[], int M, int value)
{
    int home = value % M, j = 0;
    for (int i = 0; i < v[home].size(); i++)
    {
        if (v[home][j] == value)
            return true;
        j++;
    }
    return false;
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
void contain(vector<int> v[], int M, int value)
{
    if (search(v, M, value))
        cout << "True" << endl;
    else
        cout << "False" << endl;
}
int main()
{
    int M = 10;
    vector<int> arr[10];
    vector<int> v1 = {133, 88, 92, 221, 174, 43, 11, 1008, 444, 100, 540, 120};
    for (int i = 0; i < v1.size(); i++)
        insert(arr, M, v1[i]);
    printtable(arr, M);
    contain(arr, M, 1008);
    contain(arr, M, 108);
}