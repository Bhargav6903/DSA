#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
struct Node *first = NULL;

void ladd(int n)
{
    struct Node *head = new Node;
    head->data = n;
    head->next = first;
    first = head;
}
void print(struct Node *p, int n)
{
    int count = 0;
    bool flag = false;
    while (p != NULL)
    {
        count++;
        if (p->data == n)
        {
            cout << count;
            flag = true;
            break;
        }
        p = p->next;
    }
    if (!flag)
        cout << "Element not found";
}

int main()
{

    ladd(3);
    ladd(5);
    ladd(6);
    ladd(2);
    ladd(1);
    ladd(10); // 2Linked list is: 10-> 1-> 2-> 6-> 5-> 3-> NULL

    print(first, 5);
}
