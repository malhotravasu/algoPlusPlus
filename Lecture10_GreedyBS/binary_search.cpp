#include <bits/stdc++.h>
using namespace std;
#define epsilon 1e-7

int lower_bound(int key, int i, int j, vector<int> &arr)
{
    if (i>j)
        return numeric_limits<int>::max();
    int mid = (i+j)/2;
    
    int ans = numeric_limits<int>::max();
    if (key == arr[mid])
        ans = min(mid, lower_bound(key, i, mid-1, arr));
    else if (key < arr[mid])
        ans = lower_bound(key, i, mid-1, arr);
    else
        ans = lower_bound(key, mid+1, j, arr);
    return ans;
}

int upper_bound(int key, int i, int j, vector<int> &arr)
{
    if (i>j)
        return numeric_limits<int>::min();
    int mid = (i+j)/2;
    
    int ans = numeric_limits<int>::min();
    if (key == arr[mid])
        ans = max(mid, upper_bound(key, mid+1, j, arr));
    else if (key < arr[mid])
        ans = upper_bound(key, i, mid-1, arr);
    else
        ans = upper_bound(key, mid+1, j, arr);
    return ans;
}

double sqaure_root(double n)
{
    double s = 0;
    double e = n;
    double mid = (s+e)/2;
    while (abs(pow(mid, 2) - n) > epsilon)
    {
        mid = (s+e)/2;
        if (pow(mid, 2) > n)
        {
            e = mid-epsilon;
        }
        else
        {
            s = mid+epsilon;
        }
    }
    return mid;
}

int main()
{
    // int n;
    // cin >> n;
    // vector<int> arr(n);
    // for (auto &n : arr)
    //     cin >> n;
    // int key;
    // cin >> key;
    // cout << lower_bound(key, 0, n-1, arr) << '\n' << upper_bound(key, 0, n-1, arr);
    double n;
    cin >> n;
    cout << sqaure_root(n);
}
