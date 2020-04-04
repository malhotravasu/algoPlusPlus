#include <bits/stdc++.h>

using namespace std;

int main()
{
    float threshold;
    cin >> threshold;
    float p {1};
    int people {0}, num {365};
    while (p >= threshold)
    {
        p *= num;
        p /= 365;
        num--;
        people++;
    }
    cout << people;
}