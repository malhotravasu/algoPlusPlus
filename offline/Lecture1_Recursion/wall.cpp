#include <bits/stdc++.h>

using namespace std;

int count_walls(int width)
{
    if (width < 4)
        return 1;
    return count_walls(width-1) + count_walls(width-4);
}

int main()
{
    int n;
    cin >> n;
    cout << count_walls(n);
}