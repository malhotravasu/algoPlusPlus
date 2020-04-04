#include <bits/stdc++.h>
using namespace std;

int min_coins(int N, vector<int> &coins, vector<int> &memory)
{
    if (N == 0)
        return 0;
    if (memory[N] != -1)
        return memory[N];
    
    int result = numeric_limits<int>::max();
    for (int & coin : coins)
    {
        if (coin <= N)
            result = min(min_coins(N-coin, coins, memory), result);
    }
    return memory[N] = 1 + result;
}

int min_coins_bu(int n, vector<int> &coins)
{
    vector<int> b (1000, -1);
    b[0] = 0;

    for (int j=1; j<=n; j++)
    {
        int ans = numeric_limits<int>::max();
        for (int & coin : coins)
        {
            if (j >= coin)
            {
                int subprob = b[j-coin];
                ans = min(subprob, ans);
            }
        }
        b[j] = 1+ans;
    }
    return b[n];
}

int main()
{
    int N;
    cin >> N;
    vector<int> coins {1, 5, 7};
    vector<int> memory (N+1, -1);
    cout << min_coins_bu(N, coins);
}