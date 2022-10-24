#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;
void printtable(string a1[], string a2[]);
int findPolynomial(string s)
{
    int a = s.size(), n = s.size();
    int value = 0;
    for (int i = 0; i < s.size(); i++)
    {
        value += int(s[i]) * pow(a, (n - i - 1));
    }
    return value;
}
void insert(string s, string a1[], string a2[])
{
    int i = 0, home = findPolynomial(s);
    while (a1[(home + i) % 17] != "NULL")
        i++;
    a1[(home + i) % 17] = s;

    int j = 0;
    while (a2[(home + i) % 37] != "NULL")
        j++;
    a2[(home + i) % 37] = s;
    // printtable(a1, a2);
}
void printtable(string a1[], string a2[])
{
    cout << "1st:" << endl;
    for (int i = 0; i < 17; i++)
    {
        cout << a1[i] << " ";
    }
    cout << endl;
    cout << "2nd:" << endl;

    for (int i = 0; i < 37; i++)
    {
        cout << a2[i] << " ";
    }
}
int main()
{
    int M = 17, N = 37;
    string a1[17], a2[37];
    for (int i = 0; i < 17; i++)
        a1[i] = "NULL";

    for (int i = 0; i < 37; i++)
        a2[i] = "NULL";
    // for (int i = 0; i < 17; i++)
    // {
    //     cout << a1[i] << " ";
    // }
    vector<string> v = {"fist", "sift", "shift", "fast", "faster", "shaft"};
    for (int i = 0; i < v.size(); i++)
        insert(v[i], a1, a2);

    printtable(a1, a2);
}