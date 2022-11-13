#include <bits/stdc++.h>
using namespace std;

struct Node
{
public:
    int data;
    vector<Node *> children;
    Node(int data)
    {
        this->data = data;
    }
};

Node *takeInput()
{

    int data, n;
    cout << "Data:";
    cin >> data;
    if (data == -1)
        return NULL;
    Node *temp = new Node(data);
    cout << "Enter the number of children of " << data << " : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i+1 << "th child of " << data << endl;
        Node *child = takeInput();
        temp->children.push_back(child);
    }
    return temp;
}

vector<vector<int>> breadthFirstSearch(Node *root)
{
    if (root == NULL)
        return {};
    queue<Node *> q;
    q.push(root);
    vector<vector<int>> ans;
    while (!q.empty())
    {
        int n = q.size();
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            Node *temp = q.front();
            q.pop();
            for (auto i : temp->children)
            {
                q.push(i);
            }
            v.push_back(temp->data);
        }
        ans.push_back(v);
    }
    return ans;
}

int main()
{
    Node *root = takeInput();
    vector<vector<int>> ans = breadthFirstSearch(root);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
    }

return 0;
}