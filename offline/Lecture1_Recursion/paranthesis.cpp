#include <bits/stdc++.h>

using namespace std;

int count_paranthesis(int level, int n)
{
    if (n < 0 || level < 0)
        return 0;
    if (n == 0)
    {
        if (level == 0)
            return 1;
        else
            return 0;
    }

    return count_paranthesis(level+1, n-1) + count_paranthesis(level-1, n-1);
}

int main()
{
    int n;
    cin >> n;
    cout << count_paranthesis(0, n);
}