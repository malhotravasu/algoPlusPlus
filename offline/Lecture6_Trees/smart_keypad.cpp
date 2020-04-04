#include<bits/stdc++.h>
using namespace std;

int c2i(char ch)
{
    return ch - '0';
}

void generate_subsequences(string s, size_t i, string code, vector<string> &codes)
{
    if (i == code.length()) {
        cout << s << '\n';
        return;
    }
    for (char c : codes[c2i(code[i])]) {
        generate_subsequences(s+c, i+1, code, codes);
    }
}

int main()
{
    vector<string> codes { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
	string code;
	cin >> code;
	generate_subsequences("", 0, code, codes);
	return 0;
}