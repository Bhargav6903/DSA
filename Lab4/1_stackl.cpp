#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};

class Stack
{
public:
    Node *top;
    Stack()
    {
        this->top = NULL;
    }
    void push(int val)
    {
        struct Node *temp = new Node;
        temp->data = val;
        temp->next = top;
        top = temp;
    }
    void pop()
    {
        if (isempty())
            cout << "Stack underflow" << endl;
        else
        {
            cout << top->data << " is popped" << endl;
            top = top->next;
        }
    }
    int peek()
    {
        return top->data;
    }
    bool isempty()
    {
        if (top == NULL)
            return true;
        return false;
    }
    void display()
    {
        if (isempty())
            cout << "Stack underflow" << endl;
        else
        {
            struct Node *temp;
            temp = top;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    Stack a1;
    a1.push(1);
    a1.push(2);
    a1.push(3);
    cout << "Top element is " << a1.peek() << endl;
    a1.pop();
    Stack a2;
    a2.push(4);
    a2.push(5);
    a2.push(6);
    a2.display();
    a1.display();
    return 0;
}
