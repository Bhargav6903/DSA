#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;

int hcf(int a, int b)
{
    if (a == 0)
        return b;
    return (b, (a % b));
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int a, b;
    cin >> a >> b;
    cout << hcf(max(a, b), min(a, b));
}
