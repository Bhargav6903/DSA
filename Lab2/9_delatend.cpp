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
void deletend()
{

    struct Node *t = new Node;
    if (first == NULL)
    {
        cout << "Linked list is empty";
    }

    else
    {
        t = first;

        while (t->next->next != NULL)
        {
            t = t->next;
        }
        t->next = NULL;
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

    addatend(11);
    addatend(17);
    addatend(15);
    addatend(45);
    deletend();
    display();
}
