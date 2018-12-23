#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct node{
    T data;
    node *left;
    node *right;
    node(T data) : data {data}, left {nullptr}, right {nullptr} {}
};

template <typename T>
node<T> *build()
{
    T d;
    cin >> d;

    if (d==-1)
    {
        return nullptr;
    }

    node<T> *root = new node<T>(d);
    root->left = build<T>();
    root->right = build<T>();

    return root;
}

// Pre Order printing
template <typename T>
void print_preorder(node<T> *root)
{
    if (!root)
    {
        return;
    }
    cout << root->data << ' ';
    print_preorder(root->left);
    print_preorder(root->right);
}

// In Order printing
template <typename T>
void print_inorder(node<T> *root)
{
    if (!root)
    {
        return;
    }
    print_inorder(root->left);
    cout << root->data << ' ';
    print_inorder(root->right);
}

template <typename T>
int count_nodes(node<T> *root)
{
    if (!root)
    {
        return 0;
    }
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

template <typename T>
int tree_height(node<T> *root)
{
    if (!root)
    {
        return 0;
    }
    return 1 + max(tree_height(root->left), tree_height(root->right));
}

template <typename T>
T sum_of_nodes(node<T> *root)
{
    if (!root)
    {
        return 0;
    }
    return root->data + sum_of_nodes(root->left) + sum_of_nodes(root->right);
}

template <typename T>
void print_kth_level(node<T> *root, int k)
{
    if (!root)
    {
        return;
    }
    if (k==0)
    {
        cout << root->data << ' ';
        return;
    }
    print_kth_level(root->left, k-1);
    print_kth_level(root->right, k-1);
}

// Level order Recursively
template <typename T>
void print_level_order(node<T> *root)
{
    int height = tree_height(root);
    for (int i=0; i<height; i++)
    {
        print_kth_level(root, i);
        cout << '\n';
    }
}

// Level order Iteratively ---> Breadth First Search
template <typename T>
void print_level_order_bfs(node<T> *root)
{
    queue<node<T>*> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        node<T>* front = q.front();

        if (!front)
        {
            cout << '\n';
            q.pop();
            if (!q.empty())
            {
                q.push(nullptr);
            }
            continue;
        }

        q.pop();

        cout << front->data << ' ';
        
        if (front->left)
        {
            q.push(front->left);
        }
        if (front->right)
        {
            q.push(front->right);
        }
    }
}

template <typename T>
node<T> *build_level_order()
{
    T no;
    cin >> no;
    node<T>* root = new node<T> (no);

    queue<node<T>*> q;
    q.push(root);

    while (!q.empty())
    {
        node<T>* front = q.front();
        q.pop();
        
        T a , b;
        cin >> a >> b;
        if (a!=-1)
        {
            front->left = new node<T> (a);
            q.push(front->left);
        }
        if (b!=-1)
        {
            front->right = new node<T> (b);
            q.push(front->right);
        }
    }
    return root;
}

template <typename T>
void mirror(node<T> *root)
{
    if (!root)
    {
        return;
    }
    swap(root->left, root->right);
    mirror(root->right);
    mirror(root->left);
}

template <typename T>
T sub_tree_sum(node<T> *root)
{
    if (!root)
    {
        return 0;
    }
    root->data += (sub_tree_sum(root->left) + sub_tree_sum(root->right));
    return root->data;
}

template <typename T>
T sub_tree_sum_2(node<T> *root)
{
    if (!root)
    {
        return 0;
    }

    if (!root->left && !root->right)
    {
        return root->data;
    }

    T root_data = root->data;
    root->data = sub_tree_sum_2(root->left) + sub_tree_sum_2(root->right);
    return (root_data + root->data);
}

template <typename T>
pair<int, int> diameter(node<T> *root)
{
    if (!root)
    {
        return make_pair(0, 0);
    }

    pair<int, int> left = diameter(root->left);
    pair<int, int> right = diameter(root->right);

    pair<int, int> result;
    result.first = 1 + max(left.first, right.first);
    
    int d1 = left.first + right.first;
    result.second = max({d1, left.second, right.second});
    return result;
}

int main()
{
    node<int> *root = build_level_order<int>();
    print_level_order_bfs(root);
    
    // mirror(root);
    // cout << "After Mirroring: \n";
    // print_level_order_bfs(root);

    // sub_tree_sum(root);
    // cout << "After Manipulating: \n";
    // print_level_order_bfs(root);

    // sub_tree_sum_2(root);
    // cout << "After Manipulating: \n";
    // print_level_order_bfs(root);
    
    // cout << "Diameter: " << diameter(root).second;
}