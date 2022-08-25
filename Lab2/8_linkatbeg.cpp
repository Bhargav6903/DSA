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

void addatbeg(int n)
{
    struct Node *temp = new Node;
    struct Node *t = new Node;
    temp->data = n;
    if (first == NULL)
    {
        first = temp;
        first->next = NULL;
    }

    else
    {
        temp->next = first;
        first = temp;
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

    addatbeg(5);
    addatbeg(20);
    addatbeg(15);
    addatbeg(50);
    display();
}
