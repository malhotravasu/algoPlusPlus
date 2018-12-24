#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Compare
{
    public:
        bool operator() (int &a, int &b)
        {
            return a<b;
        }
};

class Heap
{
    // Min Heap
    vector<int> v;

    public:
        Heap(int ds=32)
        {
            v.reserve(ds);
            v.push_back(-1);
        }
        bool empty()
        {
            return v.size()==1;
        }
        void heapify(int i)
        {
            int left = 2*i;
            int right = left+1;

            int min_i = i;
            if (left<v.size() && v[left]<v[min_i])
                min_i = left;
            if (right<v.size() && v[right]<v[min_i])
                min_i = right;
            
            if (min_i != i)
            {
                swap(v[i], v[min_i]);
                heapify(min_i);
            }
        }
        void push(int data)
        {
            v.push_back(data);
            int index = v.size()-1;
            int parent = index/2;

            while (index>1 && v[index]<v[parent])
            {
                swap(v[index], v[parent]);
                index = parent;
                parent = index/2;
            }
        }
        int top()
        {
            return v[1];
        }
        void pop()
        {
            int last_idx = v.size()-1;
            swap(v[1], v[last_idx]);
            v.pop_back();
            heapify(1);
        }
};

int main()
{
    Heap hp;
    int d;
    cin >> d;
    
    while (d != -1)
    {
        hp.push(d);
        cin >> d;
    }

    while (!hp.empty())
    {
        int d = hp.top();
        hp.pop();
        cout << d << ' ';
    }

    // priority_queue<int> h_max; // Max Heap
    // priority_queue<int, vector<int>, greater<int>> h_min; // Min Heap
    // priority_queue<int, vector<int>, Compare> h_min; // Custom Heap -- a<b gives Max Heap
}