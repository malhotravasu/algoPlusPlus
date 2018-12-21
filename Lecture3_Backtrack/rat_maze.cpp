#include <bits/stdc++.h>

using namespace std;

void pathExists(char maze[][5], int m, int n, int path[][5], int i, int j)
{
    if (i==m && j==n)
    {
        path[i][j] = 1;
        for (int x=0; x<=m; x++)
        {
            for (int y=0; y<=n; y++)
            {
                cout << path[x][y] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
        return;
    }
    if (i > m || j > n)
        return;
    if (maze[i][j] == 'X')
        return;
    
    path[i][j] = 1;
    pathExists(maze, m, n, path, i+1, j);
    pathExists(maze, m, n, path, i, j+1);
    path[i][j] = 0;

}

int main()
{
    int m {4}, n {5};
    char maze[4][5] = {
        "00X0",
        "0X00",
        "00XX",
        "0000"
    };
    int path[4][5] {};
    pathExists(maze, m-1, n-2, path, 0, 0);
}