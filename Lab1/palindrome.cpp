#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;

bool peli(string s, int n)
{
    if (n == s.length() / 2)
        return true;
    if (s[n - 1] == s[s.length() - n])
        return peli(s, n - 1);
    return false;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << peli(s, n);
}
