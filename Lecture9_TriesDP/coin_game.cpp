#include <bits/stdc++.h>
using namespace std;

int maximize(int i, int j, vector<int> coins, vector<vector<int>> memory)
{
    if (i > j)
        return 0;
    
    if (memory[i][j] != -1)
        return memory[i][j];
    
    int ip2_j = maximize(i+2, j, coins, memory);
    int ip1_jm1 = maximize(i+1, j-1, coins, memory);
    int i_jm2 = maximize(i, j-2, coins, memory);

    int op1 = coins[i] + min(ip2_j, ip1_jm1);
    int op2 = coins[j] + min(i_jm2, ip1_jm1);

    return memory[i][j] = max(op1, op2);
}

int main()
{
    vector<int> coins {2, 3, 1, 4};
    int N = coins.size();
    vector<vector<int>> memory (N, vector<int> (N, -1));
    cout << maximize(0, N-1, coins, memory);    
}