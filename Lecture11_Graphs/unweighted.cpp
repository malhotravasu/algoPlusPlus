#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    unordered_map<string, list<string>> g;
public:
    Graph(): V {0} {}

    void addEdge(string src, string dest, bool bidir=true)
    {
        g[src].push_back(dest);
        if (bidir)
        {
            g[dest].push_back(src);
        }
    }

    void print()
    {
        for (auto & source : g)
        {
            string src = source.first;
            auto destinations = source.second;
            cout << src << "--> ";
            for (auto & destination : destinations)
            {
                cout << '{' << destination << "} ";
            }
            cout << '\n';
        }
    }

    void dfsHelper(string node, unordered_map<string, bool> &visited)
    {
        cout << node << ' ';
        visited[node] = true;

        for (auto & child : g[node])
        {
            if (!visited[child])
                dfsHelper(child, visited);
        }
    }

    void dfs(string src)
    {
        unordered_map<string, bool> visited;
        dfsHelper(src, visited);
    }

    void bfs(string src)
    {
        set<string> visited;

        queue<pair<string, int>> path;
        path.push(make_pair(src, 0));
        visited.insert(src);

        while (!path.empty())
        {
            pair<string, int> current = path.front();
            path.pop();
            cout << current.first << ' ' << current.second << '\n';
            for (auto & destination : g[current.first])
            {
                if (visited.find(destination)==visited.end())
                {
                    path.push(make_pair(destination, current.second+1));
                    visited.insert(destination);
                }
            }
        }
    }

// Incomplete for now
    int srcToDest(string node, string dest, unordered_map<string, bool> &visited)
    {
        if (node==dest)
            return INT_MAX;
        if (visited[node])
            return INT_MAX;
        visited[node] = true;
        int min_dist = INT_MAX;
        for (auto & child : g[node])
        {
            if (!visited[child])
            {
                min_dist = min(srcToDest(child, dest, visited), min_dist);
            }
        }
        return min_dist;
    }

    int pathExists(string src, string dest)
    {
        unordered_map<string, bool> visited;
        return srcToDest(src, dest, visited);
    }
};

int main()
{
    Graph city_map;
    city_map.addEdge("Delhi", "Amritsar");
    city_map.addEdge("Lucknow", "Delhi");
    city_map.addEdge("Delhi", "Jaipur");
    city_map.addEdge("Bhopal", "Delhi");
    city_map.addEdge("Amritsar", "Jaipur");
    city_map.addEdge("Amritsar", "Haryana");
    city_map.addEdge("Jaipur", "Goa");
    city_map.addEdge("Goa", "Mumbai");

    city_map.bfs("Delhi");
    cout << '\n';
    city_map.dfs("Delhi");
}