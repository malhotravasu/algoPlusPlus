#include <iostream>
#include <queue>
using namespace std;

void balance(priority_queue<int> &maxh, priority_queue<int, vector<int>, greater<int>> &minh)
{
    if (maxh.size() > minh.size()+1)
    {
        while (maxh.size() > minh.size()+1)
        {
            minh.push(maxh.top());
            maxh.pop();
        }
        return;
    }
    else if (maxh.size() < minh.size())
    {
        while (maxh.size() < minh.size())
        {
            maxh.push(minh.top());
            minh.pop();
        }
    }
    else
        return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        priority_queue<int> maxh;
        priority_queue<int, vector<int>, greater<int>> minh;
        int n;
        cin >> n;
        while (n!=0)
        {
            if (n==-1)
            {
                if (maxh.size() == minh.size())
                {
                    if (maxh.top() < minh.top())
                    {
                        cout << maxh.top() << '\n';
                        maxh.pop();
                        balance(maxh, minh);
                    }
                    else
                    {
                        cout << minh.top() << '\n';
                        minh.pop();
                        balance(maxh, minh);
                    }
                }
                else
                {
                    cout << maxh.top() << '\n';
                    maxh.pop();
                    balance(maxh, minh);
                }
            }
            else
            {
                if (maxh.empty())
                {
                    maxh.push(n);
                }
                else
                {
                    int median = maxh.top();
                    if (n <= median)
                    {
                        maxh.push(n);
                    }
                    else
                    {
                        minh.push(n);
                    }
                    balance(maxh, minh);
                }
            }
            cin >> n;
        }
    }
}