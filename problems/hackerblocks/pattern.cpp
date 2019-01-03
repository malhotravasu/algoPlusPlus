#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int rows = n;
    int cols = (n/2)*4 + 1;
    vector<vector<int>> out (rows, vector<int> (cols, 0));
    int midr = rows/2;
    int midc = cols/2;
    out[0][midc] = 1;
    out[rows-1][midc] = 1;

    for (int i=1, offset=n-3; i<midr; i++, offset-=2)
    {
        for (int j=offset, lim=i+1; lim>=1; lim--, j++)
        {
            out[i][j] = lim;
        }
    }

    for (int i=midr, j=0, val=n/2+1; val>=1; val--, j++)
        out[i][j] = val;
    
    for (int i=midr+1, offset=2, lim=n/2; i<n; i++, offset+=2, lim--)
    {
        for (int j=offset, val=lim; val>=1; val--, j++)
        {
            out[i][j] = val;
        }
    }

    //Mirror the Pattern
    for (int i=0; i<rows; i++)
    {
        for (int j=midc-1, j_r=midc+1; j>=0; j--, j_r++)
        {
            out[i][j_r] = out[i][j];
        }
    }
    
    //Print the  output
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            if (out[i][j]==0)
            {
                cout << "..";
            }
            else
            {
                cout << out[i][j] << ' ';
            }
        }
        cout << '\n';
    }
}