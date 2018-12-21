#include <bits/stdc++.h>
using namespace std;

bool redundantParanthesis(string s)
{
    stack<char> stk;
    for (char ch : s)
    {
        if (ch != ')')
        {
            stk.push(ch);
            continue;
        }

        else
        {
            if (stk.empty())
                return true;
            if (stk.top() == '(')
                return true;
            while (stk.top() != '(')
                stk.pop();
            stk.pop();
            continue;
        }
    }
    return false;
}

int main()
{
    string s;
    cin >> s;
    cout << redundantParanthesis(s);
}