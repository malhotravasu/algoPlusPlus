#include <bits/stdc++.h>

using namespace std;

char ic2c(char i)
{
    int j = i - '0';
    return (char)(j + 'A' - 1);
}

char i2c(int i)
{
    return (char)(i + 'A' - 1);
}

void generate(string s, size_t i, string & in, vector<string> & out)
{
    if (i == in.length())
    {
        out.push_back(s);
        return;
    }

    if (i == in.length()-1)
    {
        out.push_back(s + ic2c(in[i]));
        return;
    }

    generate(s + ic2c(in[i]), i+1, in, out);
    int twoc = stoi(in.substr(i, 2));
    if (twoc <= 26)
    {
        generate(s + i2c(twoc), i+2, in, out);
    }
}

int main()
{
    string in;
    cin >> in;
    vector<string> out;
    generate("", 0, in, out);
    for (string & s : out)
        cout << s << ' ';
}