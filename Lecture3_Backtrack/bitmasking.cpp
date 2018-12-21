#include <bits/stdc++.h>

using namespace std;

int getLastBit(int n)
{
    return (n&1);
}

int getIthBit(int n, int i)
{
    return (n&(1<<i))>0 ? 1 : 0;
}

void setIthBit(int & n, int i)
{
    n = (n|(1<<i));
}

int countSetBits(int n)
{
    int count {0};
    while (n>0)
    {
        count += (n&1);
        n = n>>1;
    }
    return count;
}

int countSetBits2(int n)
{
    int count {0};
    while (n)
    {
        count++;
        n = (n&(n-1));
    }
    
    // Another Way
    // while (n)
    // {
    //     int p = n&(-n);
    //     n -= p;
    //     count++;
    // }
    return count;
}

int main()
{
    int n;
    cin >> n;

    cout << "Last bit: " << getLastBit(n) << '\n';
    cout << "Third bit: " << getIthBit(n, 3) << '\n';
    cout << "Set bits: " << countSetBits(n) << '\n';
    cout << "Using popc: " << __builtin_popcount(n) << '\n';
    cout << "Using n&(n-1): " << countSetBits2(n) << '\n';
    setIthBit(n, 3);
    cout << "After setting 3rd bit: " << n << '\n';
}