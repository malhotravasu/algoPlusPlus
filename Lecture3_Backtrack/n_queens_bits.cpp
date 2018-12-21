#include <bits/stdc++.h>

using namespace std;

int NQueenBitmask(int colM, int ldM, int rdM, const int & DONE)
{
    if (colM == DONE)
        return 1;
    
    int safe = DONE&(~(colM|ldM|rdM));
    int p;
    while (safe)
    {
        p = safe&(-safe);
        safe -= p;
    }
}

int main()
{
    int n;
    cin >> n;
    int DONE {1};
    DONE <<= n; DONE--;

}