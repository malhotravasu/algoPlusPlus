#include <bits/stdc++.h>
using namespace std;

void printStack(stack<int>& s)
{
    if (s.empty())
    {
        cout << '\n';
        return;
    }
    int top = s.top();
    cout << top << ' ';
    s.pop();
    printStack(s);
    s.push(top);
    return;
}

void insertAtBottom(stack<int>& s, int no)
{
    if (s.empty())
    {
        s.push(no);
        return;
    }
    int top = s.top();
    s.pop();
    insertAtBottom(s, no);
    s.push(top);
    return;
}

void reverseStack(stack<int>& s)
{
    if (s.empty())
        return;
    
    int top = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, top);
    return;
}

int main()
{
    stack<int> s;
    int n;
    cin >> n;
    while (n--)
    {
        int no;
        cin >> no;
        s.push(no);
    }
    printStack(s);
    reverseStack(s);
    printStack(s);
}