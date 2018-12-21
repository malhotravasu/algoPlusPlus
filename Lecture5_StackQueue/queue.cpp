#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int* arr;
    int left;
    int right;
    int capacity;
    int cs {0};

    public:
        Queue(int default_size=4)
        {
            capacity = default_size;
            arr = new int[capacity] {};
            cs = 0;
            left = right = -1;
        }
        void enqueue(int data)
        {
            if (this->empty())
            {
                left = right = 0;
                arr[right] = data;
                cs++;
                return;
            }
            if (this->full())
            {
                int* oldArr = arr;
                arr = new int[capacity <<= 1];
                for (int i=left, n=0; n<cs; n++)
                {
                    arr[n] = oldArr[i];
                    i = (i+1)%cs; 
                }
                delete[] oldArr;
                left=0;
                right=cs-1;
                right++;
                arr[right] = data;
                cs++;
                return;
            }

            right = (right+1)%capacity;
            arr[right] = data;
            cs++;
        }
        void dequeue()
        {
            if (this->empty())
            {
                cout << "Already empty!\n";
                return;
            }
            left = (left+1)%capacity;
            cs--;
        }
        int& front()
        {
            return arr[left];
        }
        bool empty()
        {
            return !cs;
        }
        bool full()
        {
            return (cs==capacity);
        }
        void printQ()
        {
            for (int n=0, i=left; n<cs; n++)
            {
                cout << arr[i] << ' ';
                i = (i+1)%capacity;
            }
            // for (int i=0; i<capacity; i++)
            // {
            //     cout << arr[i] << ' ';
            // }
            cout << '\n';
        }
        int get_capacity()
        {
            return capacity;
        }
};

int main()
{
    Queue q;

    q.enqueue(5);
    q.enqueue(3);
    q.enqueue(6);
    q.enqueue(2);
    q.enqueue(7);
    q.enqueue(2);
    q.enqueue(8);
    q.printQ();

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.printQ();

    q.enqueue(6);
    q.enqueue(2);
    q.enqueue(7);
    q.printQ();

    cout << q.get_capacity();
}