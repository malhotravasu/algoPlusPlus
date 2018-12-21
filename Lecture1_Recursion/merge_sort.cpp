#include <bits/stdc++.h>

using namespace std;

void merge(int* arr, int m, int n, int p, int q)
{
    vector<int> merged;
    int i {m}, j {p};

    while (i<=n && j<=q)
    {
        if (arr[i] < arr[j])
        {
            merged.push_back(arr[i]);
            i++;
        }
        else
        {
            merged.push_back(arr[j]);
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
}

void mergeSort(int i, int j, int* arr)
{
    if (i >= j)
        return;
    int mid = (i+j)/2;
    mergeSort(i, mid, arr);
    mergeSort(mid+1, j, arr);
    merge(arr, i, mid, mid+1, j);
}

int main()
{
    int N;
    cin >> N;
    int* arr = new int[N] {};
    for (int i=0; i<N; i++)
        cin >> arr[i];
    mergeSort(0, N-1, arr);
    for (int i=0; i<N; i++)
        cout << arr[i] << ' ';
}