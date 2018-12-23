#include<bits/stdc++.h>
using namespace std;

int c2i(char ch)
{
    return ch - '0';
}

void generate_subsequences(string s, string code, size_t i, vector<string> & codes)
{
    if (i == code.length())
        cout << s << '\n';
    for (char c : codes[c2i(code[i])])
    {
        generate_subsequences(s+c, code, i+1, codes);
    }
}

int main()
{
    vector<string> codes { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
	string code;
	getline(cin, code);
	generate_subsequences("", code, 0, codes);
	return 0;
}