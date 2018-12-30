#include <bits/stdc++.h>
using namespace std;

int min_to_1(int N, vector<int> &memory)
{
    if (N == 1)
        return memory[1] = 0;
    
    if (memory[N] != -1)
        return memory[N];
    
    int by2, by3, minus1;
    by2 = by3 = minus1 = numeric_limits<int>::max();
    
    if (N&1 != 0)
        by2 = min_to_1(N/2, memory);
    if (N%3 == 0)
        by3 = min_to_1(N/3, memory);
    minus1 = min_to_1(N-1, memory);

    return memory[N] = 1 + min({by3, by2, minus1});
}

int main()
{
    int N;
    cin >> N;
    vector<int> memory (N+1, -1);
    cout << min_to_1(N, memory);
}