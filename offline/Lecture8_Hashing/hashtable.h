#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string key;
    int value;
    Node *next;

    Node(string key, int data) : key {key}, value {data}, next {nullptr} {}

    ~Node()
    {
        if (next)
            delete next;
    }
};

class Hashtable
{
    Node **table;
    int cs;
    int ts;

    int hash_func(string key)
    {
        int index {0};
        int p {1};

        for (int i=0; i<key.length(); i++)
        {
            index = (index + (p*key[i])%ts)%ts;
            p = (p*37)%ts;
        }
        return index;
    }

    void resize()
    {
        Node **oldtable = table;
        int oldTs = ts;
        table = new Node*[ts<<=1] {};
        cs=0;
        for (int i=0; i<oldTs; i++)
        {
            Node *temp = oldtable[i];
            while (temp)
            {
                insert(temp->key, temp->value);
                temp = temp->next;
            }
        }
        delete[] oldtable;
    }

    // (A+B)%m = (A%m + B%m)%m
    public:

        Hashtable(int ds=11)
        {
            cs=0;
            ts = ds;
            table = new Node*[ts] {};
        }

        void insert(string key, int value)
        {
            int index = hash_func(key);
            Node *n = new Node(key, value);
            n->next = table[index];
            table[index] = n;
            cs++;

            float load_factor = cs/(float)ts;
            if (load_factor > 0.7)
                resize();
        }

        void print()
        {
            for (int i=0; i<ts; i++)
            {
                cout << "Bucket" << i << "==>  ";
                Node *temp = table[i];
                while (temp)
                {
                    cout << temp->key << "->" << temp->value << ' ';
                    temp = temp->next;
                }
                cout << '\n';
            }
        }

        Node *search(string key)
        {
            int index =  hash_func(key);
            Node *temp = table[index];
            while (temp)
            {
                if (temp->key == key)
                    return temp;
                temp = temp->next;
            }
            return nullptr;
        }

        int &operator[] (string key)
        {
            Node *ptr = search(key);
            if (!ptr)
            {
                this->insert(key, 0);
                return search(key)->value;
            }
            else
            {
                return ptr->value;
            }
        }
};