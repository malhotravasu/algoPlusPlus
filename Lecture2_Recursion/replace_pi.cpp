#include <bits/stdc++.h>

using namespace std;

void replace_pi(char * s, size_t n)
{
    if (n <= 1)
        return;
    if (s[0] == 'p' && s[1] == 'i')
    {
        s[0] = '3';
        s[1] = '.';
        int i;
        for (i=2; s[i]!='\0'; i++);
        for (; i>=2; i--)
            s[i+2] = s[i];
        s[2] = '1';
        s[3] = '4';
        replace_pi(s+4, n-2);
    }
    else
    {
        replace_pi(s+1, n-1);
    }
}

int main()
{
    char s[1000];
    cin >> s;
    replace_pi(s, strlen(s));
    cout << s;
}