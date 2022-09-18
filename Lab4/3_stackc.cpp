#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;
struct Node
{
    char data;
    struct Node *next;
} *top = NULL;

class Stack
{
public:
    void push(char val)
    {
        struct Node *temp = new Node;
        temp->data = val;
        temp->next = top;
        top = temp;
    }
    void pop()
    {
        if (top == NULL)
            cout << "Stack underflow" << endl;
        else
        {
            top = top->next;
        }
    }
    bool isempty()
    {
        if (top == NULL)
            return true;
        return false;
    }
    char peek()
    {
        return top->data;
    }

    bool solve(string s)
    {
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            // cout << s[i] << " ";
            if (s[i] == '/')
                count++;
            else if (count == 2)
                break;
            else if (s[i] != '(' && s[i] != '{' && s[i] != '[' && s[i] != ')' && s[i] != '}' && s[i] != ']')
                continue;
            else if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                push(s[i]);
            else
            {
                if (isempty())
                    return false;

                if (peek() == '(' && s[i] == ')')
                {
                    pop();
                }
                else if (peek() == '{' && s[i] == '}')
                {
                    pop();
                }
                else if (peek() == '[' && s[i] == ']')
                {
                    pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if (!isempty())
            return false;
        return true;
    }
};

int main()
{
    Stack a1;
    cout << a1.solve("cout int value(int arr[n]//)");

    return 0;
}
