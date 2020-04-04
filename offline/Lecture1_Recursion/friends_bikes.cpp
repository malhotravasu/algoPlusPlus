#include <bits/stdc++.h>

using namespace std;

int count_recursive(int f)
{
    if (f <= 2)
        return f;
    
    return count_recursive(f-1) + (f-1)*count_recursive(f-2);
}

int main()
{
    int n;
    cin >> n;
    cout << count_recursive(n);
}