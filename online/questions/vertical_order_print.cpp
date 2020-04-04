#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data) : data {data}, left {nullptr}, right {nullptr} {}
};

void print_in_order(Node *root)
{
    if (!root)
    {
        return;
    }
    cout << root->data << ' ';
    print_in_order(root->left);
    print_in_order(root->right);
}

int main()
{
    int N;
    cin >> N;
    int first; cin >> first;
    Node *root = new Node(first);
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        int a, b;
        cin >> a >> b;

        if (a!=-1)
        {
            front->left = new Node(a);
            q.push(front->left);
        }
        if (b!=-1)
        {
            front->right = new Node(b);
            q.push(front->right);
        }
    }
    print_in_order(root);
}