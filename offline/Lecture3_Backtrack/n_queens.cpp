#include <bits/stdc++.h>

using namespace std;

bool safeMove(int board[][100], int n, int x, int y)
{
    for (int i=0, j=y; i<n; i++)
    {
        if (i==x && j==y)
            continue;
        if (board[i][j] == 1)
            return false;
    }

    for (int i=x-1, j=y-1; ; i--, j--)
    {
        if (i < 0 || j < 0)
            break;
        if (board[i][j] == 1)
            return false;
    }

    for (int i=x-1, j=y+1; ; i--, j++)
    {
        if (i < 0 || j == n)
            break;
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

int NQueen(int board[][100], int n, int i)
{
    if (i == n)
    {
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
        return 1;
    }
    int result {0};
    for (int j=0; j<n; j++)
    {
        if (safeMove(board, n, i, j))
        {
            board[i][j] = 1;
            result += NQueen(board, n, i+1);
            board[i][j] = 0;
        }
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    int board[100][100] {};
    int states = NQueen(board, n, 0);
    cout << "Total possible States: " << states << '\n';
}