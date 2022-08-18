#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;
int fibo(int a)
{
    if (a == 1)
        return 0;
    else if (a == 2)
        return 1;
    else if (a <= 0)
        return -1;
    else
        return fibo(a - 1) + fibo(a - 2);
}
int fiboi(int a)
{
    int x = 0, y = 1, sum = 0;
    if (a <= 0)
        return -1;
    else if (a == 1)
        return 0;
    else
    {
        for (int i = 3; i <= a; i++)
        {
            sum = x + y;
            x = y;
            y = sum;
        }
        return sum;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    if (fibo(n) == -1)
        cout << "Wrong input" << endl;
    else
        cout << fibo(n) << endl;
    return 0;
}
