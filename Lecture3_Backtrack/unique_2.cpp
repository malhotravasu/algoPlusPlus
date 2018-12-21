#include <bits/stdc++.h>

using namespace std;

void getUnique(vector<int> & arr)
{
    int temp {0};
    for (int & elem : arr)
        temp ^= elem;
    int last = (temp&(-temp));
    int unique1 {0};
    for (int & elem : arr)
    {
        if (elem&last)
            unique1 ^= elem;
    }
    cout << "Unique 1: " << unique1 << '\n';
    cout << "Unique 2: " << (unique1^temp);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr (n);
    for (int & elem : arr)
        cin >> elem;
    getUnique(arr);
}