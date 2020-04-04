#include <bits/stdc++.h>

using namespace std;

int NQueenBitmask(int colM, int ldM, int rdM, const int & DONE)
{
    if (colM == DONE)
        return 1;
    
    int safe = DONE&(~(colM|ldM|rdM));
    int p;
    int result {0};
    while (safe)
    {
        p = safe&(-safe);
        safe -= p;
        result += NQueenBitmask(colM|p, (ldM|p)<<1, (rdM|p)>>1, DONE);
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    int DONE {1};
    DONE <<= n; DONE--;
    cout << NQueenBitmask(0, 0, 0, DONE);
}