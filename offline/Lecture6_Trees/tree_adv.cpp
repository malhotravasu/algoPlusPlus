#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data) : data {data}, left {nullptr}, right {nullptr} {}
};

Node *build_level_order()
{
    int no;
    cin >> no;
    Node* root = new Node (no);

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node* front = q.front();
        q.pop();
        
        int a , b;
        cin >> a >> b;
        if (a!=-1) {
            front->left = new Node (a);
            q.push(front->left);
        }
        if (b!=-1) {
            front->right = new Node (b);
            q.push(front->right);
        }
    }
    return root;
}

Node *build_from_array(int *arr, int l, int r)
{
    if (l>r) {
        return nullptr;
    }

    int mid = (l+r)/2;
    Node *root = new Node (arr[mid]);

    root->left = build_from_array(arr, l, mid-1);
    root->right = build_from_array(arr, mid+1, r);

    return root;
}

void print_level_order_bfs(Node *root)
{
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty()) {
        Node* front = q.front();

        if (!front) {
            cout << '\n';
            q.pop();
            if (!q.empty()) {
                q.push(nullptr);
            }
            continue;
        }

        q.pop();

        cout << front->data << ' ';
        
        if (front->left) {
            q.push(front->left);
        }
        if (front->right) {
            q.push(front->right);
        }
    }
}

void root_to_leaf(string path, Node *root)
{
    if (!root) {
        return;
    }
    if (!root->left && !root->right) {
        path += to_string(root->data);
        cout << path << '\n';
        return;
    }
    path += to_string(root->data) + ' ';
    root_to_leaf(path, root->left);
    root_to_leaf(path, root->right);
}

int main()
{
    // int n;
    // cin >> n;
    // int *arr = new int[n];
    // for (int i=0; i<n; i++) {
    //     cin >> arr[i];
    // }
    // Node *root = build_from_array(arr, 0, n-1);
    Node *root = build_level_order();
    print_level_order_bfs(root);

    cout << '\n';
    root_to_leaf("", root);
}