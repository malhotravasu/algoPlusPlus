#include <bits/stdc++.h>
using namespace std;

long factorial(int n)
{
    long result {1};
    for (int i=1; i<=n; i++)
        result *= i;
    return result;
}

long nCr(int n, int r)
{
    if (r<n)
        return -1;
    return factorial(n)/(factorial(r)*factorial(n-r));
}

long catalan(int n)
{
    return nCr(2*n, n)/(n+1);
}

int main()
{
    for (int i=0; i<10; i++)
    {
        cout << "Catalan " << i  << ' ' << catalan(i) << '\n';
    }
}