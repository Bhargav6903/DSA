#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};
struct Node *first = NULL;

void dubblyapp(int n)
{
    struct Node *temp = new Node;
    struct Node *t = new Node;
    if (first == NULL)
    {
        t->prev = NULL;
        t->data = n;
        t->next = NULL;
        first = t;
    }
    else
    {
        t = first;
        while (t->next != NULL)
            t = t->next;
        temp->data = n;
        t->next = temp;
        temp->prev = t;
        temp->next = NULL;
    }
}
void dubbly_remove(int n)
{
    struct Node *temp = new Node;
    struct Node *t = new Node;
    if (first == NULL)
    {
        cout << "Link list is empty";
    }
    else
    {
        t = first;
        while (t->data != n)
            t = t->next;
        t->prev->next = t->next;
        if (t->next)
            t->next->prev = t->prev;
    }
}

void display()
{

    while (first != NULL)
    {
        cout << first->data << " ";
        first = first->next;
    }
}
int main()
{
    dubblyapp(4);
    dubblyapp(14);
    dubblyapp(44);
    dubblyapp(114);
    dubbly_remove(114);
    display();
}
