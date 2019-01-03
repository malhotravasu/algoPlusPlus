#include <bits/stdc++.h>
using namespace std;

vector<int> board(37, 0);


class Graph
{
    int V;
    list<int> *l;
public:
    Graph(int V)
    {
        l = new list<int>[V+1];
        V = V+1;
    }
    void addEdge(int u, int v)
    {
        l[u].push_back(v);
    }
};

int main()
{
    Graph g (36);

    for (int i=1; i<=36; i++)
    {
        for (int dice=1; dice<=36; dice++)
        {
            int j = i+dice;
            j += board[j];
            if (j<=36)
            {

            }
        }
    }
}