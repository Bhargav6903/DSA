#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;
struct node
{
    int data;
    struct node *next;
};

class QUEUE
{
public:
    struct node *front;
    struct node *rear;

    QUEUE()
    {
        this->front = NULL;
        this->rear = NULL;
    }
    void enque(int x)
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
    void dequeue()
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
            front = front->next;
            free(ptr);
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
    QUEUE a1;
    a1.enque(20);
    a1.enque(30);
    a1.enque(50);
    a1.enque(11);
    a1.dequeue();
    cout << a1.quelength() << endl;
    a1.Display();
    return 0;
}
