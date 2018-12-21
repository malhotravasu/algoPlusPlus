#include<bits/stdc++.h>
using namespace std;

vector<int> getPrimes(int n=100001)
{
    bool* arr = new bool[n] {};
    int lim = sqrt(n)+1;
    for (int i=2; i<=lim; i++)
    {
        if (arr[i])
            continue;
        for (int j=2*i; j<n; j+=i)
        {
            arr[j] = true;
        }
    }
    vector<int> primes;
    primes.reserve(10000);
    for (int i=2; i<n; i++)
    {
        if (!arr[i])
            primes.push_back(i);
    }
    return primes;
}

void printStack(stack<int>& s)
{
    while (!s.empty())
    {
        int top = s.top();
        s.pop();
        cout << top << '\n';
    }
}

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<stack<int>> A (Q+1);
    vector<stack<int>> B (Q+1);
    for (int i=0; i<N; i++)
    {
        int no;
        cin >> no;
        A[0].push(no);
    }
    vector<int> primes = getPrimes();
    for (int i=1; i<=Q; i++)
    {
        while (!A[i-1].empty())
        {
            int top = A[i-1].top();
            A[i-1].pop();
            if (top%primes[i-1] == 0)
                B[i].push(top);
            else
                A[i].push(top);
        }
    }
    for (int i=1; i<=Q; i++)
        printStack(B[i]);
    printStack(A[Q]);
}