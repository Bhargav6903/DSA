#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;
double fact(double a)
{
    if (a == 0 || a == 1)
        return 1;
    else if (a != ceil(a))
        return 0;
    else if (a < 0)
        return 0;
    else
        return a * fact(a - 1);
}
int facti(int a)
{
    if (a < 0)
        return 0;
    else if (a != ceil(a))
        return 0;
    else
    {
        int sum = 1;
        for (int i = a; i >= 1; i--)
            sum *= i;

        return sum;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    double n;
    cin >> n;
    if (fact(n) == 0)
        cout << "Wrong input " << endl;
    else
        cout << fact(n) << endl;
    return 0;
}
