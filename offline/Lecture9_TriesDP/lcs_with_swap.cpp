#include <bits/stdc++.h>
using namespace std;

int lcs(int i, int j, int k, string &s1, string &s2)
{
    if (i>=s1.length() || j>=s2.length())
        return 0;
    if (s1[i] == s2[j])
        return 1+lcs(i+1, j+1, k, s1, s2);
    int ans = numeric_limits<int>::min();
    if (k>0)
        ans = 1+lcs(i+1, j+1, k-1, s1, s2);
    return max({
        lcs(i+1, j, k, s1, s2),
        lcs(i, j+1, k, s1, s2),
        ans
    });
}

int main()
{
    string s1="hello", s2="hollow";
    cout << lcs(0, 0, 2, s1, s2);
}