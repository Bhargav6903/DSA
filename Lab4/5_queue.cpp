#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;
struct node
{
    int data;
    int prio;
    struct node *next;
};
class Q1
{
public:
    struct node *front;
    Q1()
    {
        this->front = NULL;
    }
    void insert(int x, int p)
    {
        node *temp = new node();
        node *ptr = new node();
        temp->data = x;
        temp->prio = p;
        if (front == NULL || front->prio > p)
        {
            temp->next = front;
            front = temp;
            return;
        }
        ptr = front;
        while (ptr->next != NULL && ptr->next->prio <= p)
            ptr = ptr->next;
        temp->next = ptr->next;
        ptr->next = temp;
    }
    void del()
    {

        if (front == NULL)
            printf("Queue Underflow\n");
        else
        {
            front = front->next;
        }
    }
    bool isempty()
    {
        if (front == NULL)
            return true;
        else
            return false;
    }
    int quelength()
    {
        node *temp = front;
        int count = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }
    void Display()
    {
        node *ptr;
        ptr = front;
        if (front == NULL)
            cout << "Queue is empty\n";
        else
        {
            cout << "Queue is :\n";
            cout << "Priority   Item\n";
            while (ptr != NULL)
            {
                cout << ptr->prio << "           " << ptr->data << endl;
                ptr = ptr->next;
            }
        }
    }
};

int main()
{
    Q1 a1;
    a1.insert(20, 2);
    a1.insert(30, 1);
    a1.insert(50, 7);
    a1.insert(10, 5);
    a1.del();
    a1.Display();
    return 0;
}
