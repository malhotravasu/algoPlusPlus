#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node *left;
    Node *right;
    Node(T data) : data {data}, left {nullptr}, right {nullptr} {}
};

template <typename T>
Node<T> *build()
{
    T d;
    cin >> d;

    if (d==-1)
    {
        return nullptr;
    }

    Node<T> *root = new Node<T>(d);
    root->left = build<T>();
    root->right = build<T>();

    return root;
}

// Pre Order printing
template <typename T>
void print_preorder(Node<T> *root)
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
void print_inorder(Node<T> *root)
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
int count_nodes(Node<T> *root)
{
    if (!root)
    {
        return 0;
    }
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

template <typename T>
int tree_height(Node<T> *root)
{
    if (!root)
    {
        return 0;
    }
    return 1 + max(tree_height(root->left), tree_height(root->right));
}

template <typename T>
T sum_of_nodes(Node<T> *root)
{
    if (!root)
    {
        return 0;
    }
    return root->data + sum_of_nodes(root->left) + sum_of_nodes(root->right);
}

template <typename T>
void print_kth_level(Node<T> *root, int k)
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
void print_level_order(Node<T> *root)
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
void print_level_order_bfs(Node<T> *root)
{
    queue<Node<T>*> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        Node<T>* front = q.front();

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
Node<T> *build_level_order()
{
    T no;
    cin >> no;
    Node<T>* root = new Node<T> (no);

    queue<Node<T>*> q;
    q.push(root);

    while (!q.empty())
    {
        Node<T>* front = q.front();
        q.pop();
        
        T a , b;
        cin >> a >> b;
        if (a!=-1)
        {
            front->left = new Node<T> (a);
            q.push(front->left);
        }
        if (b!=-1)
        {
            front->right = new Node<T> (b);
            q.push(front->right);
        }
    }
    return root;
}

template <typename T>
void mirror(Node<T> *root)
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
T sub_tree_sum(Node<T> *root)
{
    if (!root)
    {
        return 0;
    }
    root->data += (sub_tree_sum(root->left) + sub_tree_sum(root->right));
    return root->data;
}

template <typename T>
T sub_tree_sum_2(Node<T> *root)
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
pair<int, int> diameter(Node<T> *root)
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

template <typename T>
pair<bool, int> check_balanced(Node<T> *root)
{
    if (!root)
    {
        return make_pair(true, 0);
    }

    pair<int, int> left = check_balanced(root->left);
    pair<int, int> right = check_balanced(root->right);

    pair<int, int> result;
    result.first = abs(left.second - right.second)<2 && left.first && right.first;
    result.second = 1 + max(left.second, right.second);

    return result;
}

template <typename T>
int get_index(T key, T *in, int l, int r)
{
    for (int i=l; i<=r; i++) {
        if (key == in[i]) {
            return i;
        }
    }
    return -1;
}

template <typename T>
Node<T> *build_from_traversals(queue<T> &pre, T *in, int l, int r)
{
    if (l>r || pre.empty()) {
        return nullptr;
    }

    T root_data = pre.front();
    pre.pop();

    int index = get_index(root_data, in, l, r);
    if (index==-1) {
        return nullptr;
    }
    Node<T> *root = new Node<T>(root_data);
    root->left = build_from_traversals(pre, in, l, index-1);
    root->right = build_from_traversals(pre, in, index+1, r);
    return root;
}

// int main()
// {
//     // Node<int> *root = build_level_order<int>();
//     // print_level_order_bfs(root);
    
//     // mirror(root);
//     // cout << "After Mirroring: \n";
//     // print_level_order_bfs(root);

//     // sub_tree_sum(root);
//     // cout << "After Manipulating: \n";
//     // print_level_order_bfs(root);

//     // sub_tree_sum_2(root);
//     // cout << "After Manipulating: \n";
//     // print_level_order_bfs(root);
    
//     // cout << "Diameter: " << diameter(root).second;

//     // cout << "Result: " << check_balanced(root).first;

//     int N;
//     cin >> N;
//     queue<int> pre;
//     for (int i=0, node; i<N; i++) {
//         cin >> node;
//         pre.push(node);
//     }
//     int *in = new int[N];
//     for (int i=0; i<N; i++) {
//         cin >> in[i];
//     }
//     Node<int> *root = build_from_traversals(pre, in, 0, N-1);
    
//     print_preorder(root);
//     cout << '\n';
//     print_inorder(root);
//     cout << "\n\n";
//     print_level_order_bfs(root);
// }