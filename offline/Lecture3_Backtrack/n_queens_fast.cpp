#include <bits/stdc++.h>

using namespace std;

int l[100] {0}, r[100] {0}, c[30] {0};

long countNQueen(int n, int i)
{
    if (i == n)
    {
        return 1;
    }
    long result {0};
    for (int j=0; j<n; j++)
    {
        if (!c[j] && !r[i+j] && !l[i-j+n-1])
        {
            c[j] = r[i+j] = l[i-j+n-1] = 1;
            result += countNQueen(n, i+1);
            c[j] = r[i+j] = l[i-j+n-1] = 0;
        }
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    for (int i=1; i<=n; i++)
        cout << "Total possible States for N = " << i << " : " << countNQueen(i, 0) << '\n';
}