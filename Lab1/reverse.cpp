#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;
string rev(string str)
{
    if (str.length() <= 1)
        return str;
    return rev(str.substr(1)) + str[0];
}

void rev2(string str, int n)
{
    if (n == str.length())
        return;
    rev2(str, n + 1);
    cout << str[n];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string str = "ABCF";
    rev2(str, 0);
    // cout << str.substr(1);
}
