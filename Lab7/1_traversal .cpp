#include <bits/stdc++.h>
using namespace std;

struct Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

void preOrder(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> s;
    s.push(root);

    while (!s.empty())
    {
        Node *temp = s.top();
        s.pop();
        cout << temp->data << " ";

        if (temp->right)
            s.push(temp->right);
        if (temp->left)
            s.push(temp->left);
    }
}

void postOrder(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> s;
    Node *temp = root;
    Node *prev = NULL;
    while (temp != NULL || !s.empty())
    {
        if (temp != NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
        else
        {
            temp = s.top();
            if (temp->right == NULL || temp->right == prev)
            {
                cout << temp->data << " ";
                s.pop();
                prev = temp;
                temp = NULL;
            }
            else
                temp = temp->right;
        }
    }
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;
    Node *temp = root;
    stack<Node *> s;
    while (temp != NULL || !s.empty())
    {
        if (temp != NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
        else
        {
            temp = s.top();
            s.pop();
            cout << temp->data << " ";

            temp = temp->right;
        }
    }
}

Node *takeInput()
{

    int data;
    cout << "data:";
    cin >> data;
    if (data == -1)
        return NULL;
    Node *temp = new Node(data);
    cout << "Enter left child of " << data << endl;
    Node *leftTree = takeInput();
    cout << "Enter right child of " << data << endl;
    Node *rightTree = takeInput();

    temp->left = leftTree;
    temp->right = rightTree;
    return temp;
}

int main()
{
    Node *root = takeInput();
    cout << "PreOrder: ";
    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    cout << "InOrder: ";
    inOrder(root);
    cout << endl;
    cout << "PostOrder: ";
    postOrder(root);
    cout << endl;
    return 0;
}