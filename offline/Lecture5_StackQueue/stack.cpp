#include <bits/stdc++.h>
using namespace std;

// Getting minimum using extra space
// template <typename T>
// class Stack
// {
//     vector<T> arr;
//     vector<T> mins;
//     public:
//         void push(T no)
//         {
//             if (empty())
//             { 
//                 arr.push_back(no);
//                 mins.push_back(no);
//                 return;
//             }
//             if (no <= mins.back())
//                 mins.push_back(no);
//             arr.push_back(no);
//             return;
//         }
//         void pop()
//         {
//             if (empty())
//             {
//                 cout << "Stack Empty!";
//                 return;
//             }
//             if (mins.back() == top())
//             {
//                 mins.pop_back();
//             }
//             arr.pop_back();
//         }
//         T& top()
//         {
//             return arr.back();
//         }
//         bool empty()
//         {
//             return arr.empty();
//         }
//         void clear()
//         {
//             while (!empty())
//             {
//                 cout << top() << ' ';
//                 pop();
//             }
//             cout << '\n';
//             mins.clear();
//         }
//         T getMin()
//         {
//             return mins.back();
//         }
// };

// Getting minimum with O(1) Space Complexity
template <typename T>
class Stack
{
    vector<T> arr;
    T minel = numeric_limits<T>::max();
    public:
        void push(T no)
        {
            if (this->empty())
            { 
                arr.push_back(no);
                minel = no;
                return;
            }
            if (no < minel)
            {
                T temp = no;
                no = (2*no - minel);
                minel = temp;
            }
            arr.push_back(no);
            return;
        }
        void pop()
        {
            if (this->empty())
            {
                cout << "Stack Empty!";
                return;
            }
            if (arr.back() < minel)
            {
                minel = (2*minel - arr.back());
            }
            arr.pop_back();
            return;
        }
        T top()
        {
            if (arr.back() < minel)
                return (2*minel - arr.back()); 
            return arr.back();
        }
        bool empty()
        {
            return arr.empty();
        }
        void clear()
        {
            arr.clear();
            minel = numeric_limits<T>::max();
        }
        T getMin()
        {
            return minel;
        }
};

int main()
{
    Stack<int> s;

    s.push(-1);
    s.push(3);
    s.push(4);
    s.push(6);
    cout << s.getMin() << '\n';

    s.push(-3);
    cout << s.getMin() << '\n';

    s.push(-5);
    cout << s.getMin() << '\n';
    
    s.pop();
    cout << s.getMin() << '\n';

    s.pop();
    cout << s.getMin();
}