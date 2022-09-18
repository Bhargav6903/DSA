#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;
struct node
{
    int data;
    struct node *next;
};

class Queue
{
    struct node *front;
    struct node *rear;

public:
    Queue()
    {
        this->front = NULL;
        this->rear = NULL;
    }
    void enqueAtlast(int x)
    {
        node *temp = new node();
        temp->data = x;
        temp->next = NULL;
        if (front == NULL)
        {
            front = temp;
            rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
    }
    void enqueAtfront(int x)
    {
        node *temp = new node();
        temp->data = x;
        temp->next = NULL;
        if (front == NULL)
        {
            front = temp;
            rear = temp;
            return;
        }

        temp->next = front;
        front = temp;
    }
    void dequeueAtfront()
    {

        if (front == NULL)
        {
            cout << "Underflow";
            return;
        }
        if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            node *ptr = front;
            front = front->next;
            free(ptr);
        }
    }

    void dequeueAtlast()
    {

        if (front == NULL)
        {
            cout << "Underflow";
            return;
        }
        if (front == rear)
        {
            free(front);
            front = rear = NULL;
        }
        else
        {
            node *ptr = front;
            node *p1 = new node();
            while (ptr->next != NULL)
            {
                p1 = ptr;
                ptr = ptr->next;
            }
            p1->next = NULL;
            rear = p1;
        }
    }
    bool isempty()
    {
        if (front == NULL && rear == NULL)
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

        if ((front == NULL) && (rear == NULL))
        {
            cout << "Queue is empty" << endl;
            return;
        }
        node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue a1;
    a1.enqueAtlast(10);
    a1.enqueAtlast(20);
    a1.enqueAtlast(30);
    a1.enqueAtlast(35);
    a1.enqueAtfront(5);
    a1.Display();
    a1.dequeueAtfront();
    a1.dequeueAtlast();
    a1.Display();
    return 0;
}
