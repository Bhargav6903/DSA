#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;
void second();
void third();
void fourth();

void first()
{
    second();
    cout << "I am the first" << endl;
}
void second()
{

    third();
    cout << "I am the second" << endl;
}
void third()
{

    fourth();
    cout << "I am the third" << endl;
}
void fourth()
{

    cout << "I am the fourth" << endl;
    int main();
}
int main()
{
    first();
}
