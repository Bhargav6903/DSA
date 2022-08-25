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
bool flag = false;
void addatend(int n)
{
    struct Node *temp = new Node;
    struct Node *t = new Node;
    temp->data = n;
    temp->next = NULL;
    if (first == NULL)
    {
        first = temp;
    }

    else
    {
        t = first;
        while (t->next != NULL)
        {
            t = t->next;
        }

        t->next = temp;
    }
}
void replace(int n, int r)
{

    struct Node *t = new Node;
    if (first == NULL)
    {
        cout << "Linked list is empty";
    }

    else
    {
        t = first;

        while (t->next != NULL)
        {
            if (t->data == n)
            {
                t->data = r;
                break;
            }
            t = t->next;
        }
        if (t->next != NULL)
            flag = true;
        else
            flag = false;
    }
}
void display()
{
    if (flag)
    {
        while (first != NULL)
        {
            cout << first->data << " ";
            first = first->next;
        }
    }
    else
        cout << -1;
}
int main()
{

    addatend(11);
    addatend(17);
    addatend(15);
    addatend(45);
    replace(19, 33);
    display();
}
