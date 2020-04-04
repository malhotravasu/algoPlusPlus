#include <bits/stdc++.h>

using namespace std;

int merge(int* arr, int m, int n, int p, int q)
{
    vector<int> merged;
    int i {m}, j {p};

    int inversions {0};
    while (i<=n && j<=q)
    {
        if (arr[i] <= arr[j])
        {
            merged.push_back(arr[i]);
            i++;
        }
        else
        {
            merged.push_back(arr[j]);
            inversions += (n-i+1);
            j++;
        }
    }
    for (; i<=n; i++)
        merged.push_back(arr[i]);
    for (; j<=q; j++)
        merged.push_back(arr[j]);
    for (int i=m, j=0; i<=q; i++, j++)
    {
        arr[i] = merged[j];
    }
    return inversions;
}

int countInv(int i, int j, int* arr)
{
    if (i >= j)
        return 0;
    int mid = (i+j)/2;
    int x = countInv(i, mid, arr);
    int y = countInv(mid+1, j, arr);
    int z = merge(arr, i, mid, mid+1, j);
    return x+y+z;
}

int main()
{
    int N;
    cin >> N;
    int* arr = new int[N] {};
    for (int i=0; i<N; i++)
        cin >> arr[i];
    int result = countInv(0, N-1, arr);
    cout << result;
}