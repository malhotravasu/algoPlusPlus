#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T>* next;

    Node(T d)
    {
        data = d;
        next = nullptr;
    }
};

template <typename T>
void insertAtHead(Node<T>*& head, T data)
{
    if (!head)
    {
        head = new Node<T>(data);
        return;
    }
    Node<T>* n = new Node<T>(data);
    n->next = head;
    head = n;
}

template <typename T>
void delAtHead(Node<T>*& head)
{
    if (!head)
        return;
    Node<T>* temp = head;
    head = head->next;
    delete temp;
}

template <typename T>
void printLL(Node<T>* head)
{
    while(head!=nullptr)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "\\0\n";
}

template <typename T>
bool searchLL(Node<T>* head, T data)
{
    if (!head)
        return false;
    if (head->data == data)
        return true;
    return searchLL(head->next, data);
}

// Recursive approach
template <typename T>
Node<T>* reverseLLRecursive(Node<T>* head)
{
    if (!head->next)
    {
        return head;
    }
    Node<T>* reversed = reverseLLRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return reversed;
}

template <typename T>
void reverseLL(Node<T>*& head)
{
    Node<T> *pichhla=nullptr, *curr=head, *agla;
    while (curr)
    {
        agla = curr->next;
        curr->next = pichhla;
        pichhla = curr;
        curr = agla;
    }
    head = pichhla;
}

template <typename T>
Node<T>* merge(Node<T>* a, Node<T>* b)
{
    if (!a)
        return b;
    if (!b)
        return a;

    Node<T>* small;
    if (a->data < b->data)
    {
        small = a;
        a = a->next;
    }
    else
    {
        small = b;
        b = b->next;
    }
    small->next = merge(a, b);
    return small;
}

template <typename T>
Node<T>* midLL(Node<T>* head)
{
    Node<T>* slow = head;
    Node<T>* fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

template <typename T>
Node<T>* mergeSortLL(Node<T>* ll)
{
    if (!ll || !ll->next)
        return ll;

    Node<T>* mid = midLL(ll);
    Node<T>* a = ll;
    Node<T>* b = mid->next;
    mid->next = nullptr;

    a = mergeSortLL(a);
    b = mergeSortLL(b);
    return merge(a, b);
}

int main()
{
    Node<int>* ll = nullptr;
    insertAtHead(ll, 1);
    insertAtHead(ll, 8);
    insertAtHead(ll, 2);
    insertAtHead(ll, 7);
    insertAtHead(ll, 3);
    insertAtHead(ll, 6);
    insertAtHead(ll, 4);
    insertAtHead(ll, 5);
    printLL(ll);

    ll = mergeSortLL(ll);
    printLL(ll);

    delAtHead(ll);
    printLL(ll);

    // if (searchLL(head, 5))
    //     cout << "Yes\n";
    // if (searchLL(head, 4))
    //     cout << "Yes\n";
    // else
    //     cout << "No\n";
    
    reverseLL(ll);
    printLL(ll);

    ll = reverseLLRecursive(ll);
    printLL(ll);

    // Node<int>* merged = merge(a, b);
    // printLL(merged);
}
