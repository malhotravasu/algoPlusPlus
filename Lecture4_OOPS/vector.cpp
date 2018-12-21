#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Vector
{
    T* arr;
    int cs;
    int capacity;

    public:

        //Deep Copy Constructor
        Vector(Vector<T>& V)
        {
            cs = V.size();
            capacity = V.capacity;
            arr = new T[capacity];
            for (int i=0; i<cs; i++)
                arr[i] = V.arr[i];
        }

        Vector(int reserve=8)
        {
            capacity = reserve;
            arr = new T[capacity] {}; // Allocated on Heap
            cs = 0;
        }

        int size()
        {
            return cs;
        }
        void push_back(int data)
        {
            if (cs==capacity)
            {
                // Exapnd
                T* oldArr = arr;
                arr = new T[capacity <<= 1];

                for (int i=0; i<capacity; i++)
                    arr[i] = oldArr[i];

                //Delete Old Array
                delete[] oldArr;
            }
            arr[cs] = data;
            cs++;
        }

        void pop_back()
        {
            if (cs>0)
            {
                cs--;
            }
        }

        T at(size_t i)
        {
            return arr[i];
        }

        void operator- ()
        {
            for (int i=0; i<cs; i++)
                arr[i] *= -1;
        }
        void operator+ (T no)
        {
            for (int i=0; i<cs; i++)
                arr[i] += no;
        }

        T& operator[] (int i)
        {
            return arr[i];
        }

        ~Vector()
        {
            if (arr)
                delete[] arr;
        }
};

// Overloading without class
template <typename T>
ostream& operator<< (ostream & os, Vector<T>& v)
{
    for (int i=0; i<v.size(); i++)
        os << v[i] << ' ';
    return os;
}

template <typename T>
istream& operator>> (istream& is, Vector<T>& v)
{
    int n;
    cin >> n;
    T no;
    for (int i=0; i<n; i++)
    {
        cin >> no;
        v.push_back(no);
    }
    return is;
}

template <typename T>
Vector<T>& operator+= (Vector<T>& v1, Vector<T>& v2)
{
    for (int i=0; i<v1.size(); i++)
    {
        v1[i] += v2[i];
    }
    return v1;
}

/*
    Overloaded () Operator in an Object:
        FUnctional object | Functor
*/

int main()
{
    // for (int i=0; i<=5; i++)
    //     v.push_back(i*i);
    // cout << v;
    // -v;
    // cout << v;
    // v+3;
    // cout << v;
    // cin >> v;
    // cout << v << v;
    Vector<int> v1;
    cin >> v1;
    Vector<int> v2 (v1); // Copy Constructor

    cout << (v1+=v2);
    Vector<int> v3 = v2; // Copy Constructor
    
    Vector<int> v4;
    v4 = v3; // Copy Assignment Constructor
    
    // Vector* v5 = new Vector(v4); // Get vector on heap
    // cout << '*' << &v1 << ' ' << &v2 << ' ' << &v3 << ' ' << &v4 << ' ' << &v5 << "*\n";
    // delete v5;
}