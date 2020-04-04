#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N; 
        cin >> N;
        vector<long> rollsum (N+1, 0);
        for (int i=1; i<=N; i++)
        {
            int num;
            cin >> num;
            rollsum[i] = (num + rollsum[i-1]) % N;
            rollsum[i] = (rollsum[i]+N) % N;
        }
        vector<long> freq (N, 0);
        for (long &num : rollsum)
        {
            freq[num]++;
        }
        long result {0};
        for (long &num : freq)
        {
            if (num >= 2)
            {
                result += (num*(num-1))/2;
            }
        }
        cout << result << '\n';
    }
	return 0;
}