#include <bits/stdc++.h>
using namespace std;

int max_profit(int l, int r, int n, vector<int> &wines, vector<vector<int>> &memory)
{
    if (l > r)
        return 0;

    if (memory[l][r] != -1)
        return memory[l][r];
    
    int ansl = n*wines[l] + max_profit(l+1, r, n+1, wines, memory);
    int ansr = n*wines[r] + max_profit(l, r-1, n+1, wines, memory);

    return memory[l][r] = max(ansl, ansr);
}

int main()
{
    vector<int> wines {2, 3, 5, 1, 4};
    int N = wines.size();
    vector<vector<int>> memory (N, vector<int> (N, -1));
    cout << max_profit(0, N-1, 1, wines, memory);
}