#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data) : data {data}, left {nullptr}, right {nullptr} {}
};

void print_inorder(Node *root)
{
    if (!root)
    {
        return;
    }
    print_inorder(root->left);
    cout << root->data << ' ';
    print_inorder(root->right);
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

Node *insert_in_bst(Node *root, int data)
{
    if (!root) {
        return new Node (data);
    }
    if (data < root->data) {
        root->left = insert_in_bst(root->left, data);
    }
    else {
        root->right = insert_in_bst(root->right, data);
    }
    return root;
}

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

ostream &operator<< (ostream &os, Node *root)
{
    print_level_order_bfs(root);
    return os;
}

bool search(int key, Node *root)
{
    if (!root)
        return false;

    if (root->data == key)
        return true;

    if (root->data > key)
        return search(key, root->left);

    return search(key, root->right);
}

Node *remove_node(Node *root, int key)
{
    if (!root)
        return nullptr;

    if (key < root->data)
    {
        root->left = remove_node(root->left, key);
        return root;
    }
    
    else if (key > root->data)
    {
        root->right = remove_node(root->right, key);
        return root;
    }

    else
    {
        //0 Child
        if (!root->left && !root->right)
        {
            delete root;
            return nullptr;
        }

        //1 Child
        else if (!root->left || !root->right)
        {
            if (!root->left)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
        }

        //2 Child
        else
        {
            Node *temp = root->right;
            while (temp->left)
                temp = temp->left;
            root->data = temp->data;
            root->right = remove_node(root->right, root->data);
            return root;
        }
    }
}

struct LL
{
    Node *head = nullptr;
    Node *tail = nullptr;

    void print()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << "--> ";
            temp = temp->right;
        }
        cout << "\\0";
    }
};

LL bst_to_ll(Node *root)
{
    LL ll;

    if (!root)
        return ll;

    //0 Child
    if (!root->left && !root->right)
    {
        ll.head = root;
        ll.tail = root;
        return ll;
    }

    // 1 Child
    else if (!root->left || !root->right)
    {
        if (!root->left)
        {
            LL rightLL = bst_to_ll(root->right);
            root->right = rightLL.head;
            ll.head = root;
            ll.tail = rightLL.tail;
            return ll;
        }
        else
        {
            LL leftLL = bst_to_ll(root->left);
            leftLL.tail->right = root;
            ll.head = leftLL.head;
            ll.tail = root;
            return ll;
        }
    }

    //2 Child
    else
    {
        LL leftLL = bst_to_ll(root->left);
        LL rightLL = bst_to_ll(root->right);
        
        leftLL.tail->right = root;
        root->right = rightLL.head;
        ll.head = leftLL.head;
        ll.tail = rightLL.tail;
        return ll;
    }
}

int main()
{
    Node *root = build_level_order();
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insert_in_bst(root, data);
        cin >> data;
    }

    print_level_order_bfs(root);
    cout << "After Linked List:\n";
    LL ll = bst_to_ll(root);
    ll.print();
}