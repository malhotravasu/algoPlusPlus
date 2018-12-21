#include <bits/stdc++.h>

using namespace std;

// void subsequences(size_t i, string & arr, string s)
// {
//     if (i == arr.length())
//     {
//         cout << s << '\n';
//         return;
//     }
//     subsequences(i+1, arr, s+arr[i]);
//     subsequences(i+1, arr, s);
// }

void subsequences(size_t i, size_t j, char* in, char* out)
{
    if (in[i] == '\0')
    {
        out[j] = '\0';
        cout << out << '\n';
        return;
    }
    out[j] = in[i];
    subsequences(i+1, j+1, in, out);
    subsequences(i+1, j, in, out);
}

int main()
{
    char in[5];
    cin >> in;
    char out[5];
    subsequences(0, 0, in, out);
}