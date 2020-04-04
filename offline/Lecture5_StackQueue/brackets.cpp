#include <bits/stdc++.h>
using namespace std;

pair<int, int> get_depth(vector<int>& sequence)
{
    int depth {0};
    pair<int, int> depthInfo {0, 0};
    for (size_t i=0; i<sequence.size(); i++)
    {
        if (sequence[i]==1)
            depth++;
        else
            depth--;
        if (depth > depthInfo.first)
        {
            depthInfo.first = depth;
            depthInfo.second = i+1;
        }
    }
    return depthInfo;
}

pair<int, int> get_max_symbols(vector<int>& sequence)
{
    int depth {0}, max_len {0};
    pair<int, int> maxInfo {0, 0};
    for (size_t i=0; i<sequence.size(); )
    {
        int j=i+1;
        i++;
        depth = 1;
        max_len = 1;
        while (depth != 0)
        {
            if (sequence[i]==1)
                depth++;
            else
                depth--;
            max_len++;
            i++;
        }
        if (max_len > maxInfo.first)
        {
            maxInfo.first = max_len;
            maxInfo.second = j;
        }
    }
    return maxInfo;
}

int main()
{
    int N;
    cin >> N;
    vector<int> sequence (N);
    for (int i=0; i<N; i++)
        cin >> sequence[i];
    
    pair<int, int> depthInfo = get_depth(sequence);
    pair<int, int> maxInfo = get_max_symbols(sequence);

    cout << depthInfo.first << ' ' << depthInfo.second << ' ' << maxInfo.first << ' ' << maxInfo.second;
}