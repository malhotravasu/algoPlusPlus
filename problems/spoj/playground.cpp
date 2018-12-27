#include <iostream>
using namespace std;

struct Node 
{ 
    int data;
    Node *next; 
    Node *prev;

    Node(int d) : data {d}, next {nullptr}, prev {nullptr} {}
};

void push(Node *&tail, int data) 
{ 
    Node *new_node = new Node(data);
    tail->next = new_node; 
    new_node->prev = tail;
    tail = new_node;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int no;
    int node_count {0};
    Node *head, *tail, *mid;
    bool flag {false};
    while (cin >> no)
    {
        if (!flag)
        {
            head = tail = mid = new Node (no);
            flag = true;
            node_count = 1;
        }
        else if (no == -1)
        {
            if (node_count < 3)
            {
                if (node_count == 1)
                {
                    cout << mid->data << '\n';
                    head = tail = mid = nullptr;
                    flag = false;
                }
                else
                {
                    if (mid->next->data < mid->data)
                    {
                        mid = mid->next;
                        cout << mid->data << '\n';
                        head = tail;
                    }
                    else
                    {
                        cout << mid->data << '\n';
                        mid = head = tail;
                    }
                    tail->prev = nullptr;
                }
            }
            else if (node_count&1)
            {
                cout << mid->data << '\n';
                mid->prev->next = mid->next;
                mid->next->prev = mid->prev;
                mid = mid->prev;
            }
            else
            {
                if (mid->next->data < mid->data)
                {
                    mid = mid->next;
                    cout << mid->data << '\n';
                    mid->prev->next = mid->next;
                    mid->next->prev = mid->prev;
                    mid = mid->prev;
                }
                else
                {
                    cout << mid->data << '\n';
                    mid->prev->next = mid->next;
                    mid->next->prev = mid->prev;
                    mid = mid->next;
                }
            }
            node_count--;
        }
        else if (no == 0)
        {
            cout << '\n';
            cin.ignore(1);
            head = tail = mid = nullptr;
            flag = false;
            node_count = 0;
        }
        else
        {
            push(tail, no);
            node_count++;
            if (node_count&1)
                mid = mid->next;
        }
    }
}
