#include <bits/stdc++.h>
#include <sstream>

using namespace std;

string c2ascii(char ch)
{
    return to_string((int)ch);
}

void subsequences(size_t i, string & in, string out)
{
    if (i == in.length())
    {
        cout << out << '\n';
        return;
    }
    subsequences(i+1, in, out);
    subsequences(i+1, in, out+in[i]);
    subsequences(i+1, in, out+c2ascii(in[i]));
}

// void subsequences(size_t i, size_t j, char* in, char* out)
// {
//     if (in[i] == '\0')
//     {
//         out[j] = '\0';
//         cout << out << '\n';
//         return;
//     }
//     out[j] = in[i];
//     subsequences(i+1, j+1, in, out);
//     subsequences(i+1, j, in, out);
// }

string itos(int i)
{
    stringstream s;
    s << i;
    return s.str();
}

int main()
{
    string in;
    cin >> in;
    subsequences(0, in, "");
}