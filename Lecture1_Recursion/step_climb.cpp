#include <iostream>

using namespace std;

int stepClimb(int n, int k)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    int result = 0;
    for (int i=1; i<=k; i++)
        result += stepClimb(n-i, k);
    return result;
}

int countStrings(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
        return 2;
    else if (n == 2)
        return 3;
    else
        return countStrings(n-1) + countStrings(n-2);
}

int main()
{
    // int n, k;
    // cin >> n >> k;
    // cout << stepClimb(n, k) << '\n';

    // int n;
    // cin >> n;
    // cout << countStrings(n) << '\n';
}