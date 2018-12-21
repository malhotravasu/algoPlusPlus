#include <bits/stdc++.h>
using namespace std;

void slidingNegatives(int* arr, int n, int k)
{
    deque<int> deq;
    for (int i=0; i<k; i++)
        if (arr[i] < 0)
            deq.push_back(i);
    if (deq.empty())
        cout << 0 << ' ';
    else
        cout << arr[deq.front()] << ' ';

    for (int i=1, j=i+k-1; i<(n-k+1); i++, j++)
    {
        if (!deq.empty() && deq.front() < i)
            deq.pop_front();
        if (arr[j] < 0)
            deq.push_back(j);
        
        if (deq.empty())
            cout << 0 << ' ';
        else
            cout << arr[deq.front()] << ' ';
    }
}

int slidingMinMax(int* arr, int n, int k)
{
    deque<int> minQ;
    deque<int> maxQ;
    int min_idx {0}, max_idx {0};
    int result {0};
    for (int i=1; i<k; i++)
    {
        if (arr[i] <= arr[min_idx])
            min_idx = i;
        if (arr[i] >= arr[max_idx])
            max_idx = i;
    }
    minQ.push_back(min_idx);
    maxQ.push_back(max_idx);
    
    result += (arr[minQ.front()]+arr[maxQ.front()]);
    // cout << arr[maxQ.front()] << ' ';

    for (int i=1, j=i+k-1; i<(n-k+1); i++, j++)
    {
        if (!minQ.empty() && minQ.front() < i)
            minQ.pop_front();
        while (!minQ.empty() && (arr[j] <= arr[minQ.back()]))
            minQ.pop_back();
        minQ.push_back(j);
        
        if (!maxQ.empty() && maxQ.front() < i)
            maxQ.pop_front();
        while (!maxQ.empty() && (arr[j] >= arr[maxQ.back()]))
            maxQ.pop_back();
        maxQ.push_back(j);

        // cout << arr[maxQ.front()] << ' ';
        result += (arr[minQ.front()]+arr[maxQ.front()]);
    }
    // cout << '\n';
    return result;
}

int main()
{
    int n;
    cin >> n;
    int* arr = new int[n] {};
    for (int i=0; i<n; i++)
        cin >> arr[i];
    int k;
    cin >> k;
    cout << slidingMinMax(arr, n, k);
}