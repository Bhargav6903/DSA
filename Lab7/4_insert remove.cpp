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

Node *searchNode(Node *root, int value)
{
    if (root == NULL || root->data == value)
        return root;

    if (root->data < value)
        return searchNode(root->right, value);

    return searchNode(root->left, value);
}

Node *insertNode(Node *root, int value)
{
    Node *insert = new Node(value);
    if (!root)
    {
        root = insert;
        return root;
    }
    Node *prev = NULL;
    Node *temp = root;
    while (temp)
    {
        if (temp->data > value)
        {
            prev = temp;
            temp = temp->left;
        }
        else if (temp->data < value)
        {
            prev = temp;
            temp = temp->right;
        }
    }
    if (prev->data > value)
        prev->left = insert;
    else
        prev->right = insert;

    return temp;
}

Node *deleteNode(Node *root, int value)
{

    if (root == NULL)
        return root;

    if (root->data > value)
    {
        root->left = deleteNode(root->left, value);
        return root;
    }
    else if (root->data < value)
    {
        root->right = deleteNode(root->right, value);
        return root;
    }

    if (root->left == NULL)
    {
        Node *temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL)
    {
        Node *temp = root->left;
        delete root;
        return temp;
    }

    else
    {

        Node *newParent = root;
        Node *next = root->right;
        while (next->left != NULL)
        {
            newParent = next;
            next = next->left;
        }

        if (newParent != root)
            newParent->left = next->right;
        else
            newParent->right = next->right;

        root->data = next->data;

        delete next;
        return root;
    }
}

int findMinimum(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
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

int main()
{

    Node *root = takeInput();
    cout << "Original : ";
    inOrder(root);
    insertNode(root, 11);
    cout << "\nAfter insertion : ";
    inOrder(root);
    cout << endl;
    deleteNode(root, 11);
    inOrder(root);
    cout << "\nThe minimum is : " << findMinimum(root);

    return 0;
}