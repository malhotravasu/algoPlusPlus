#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    unordered_map<string, list<pair<string, int>>> gal;
public:
    Graph(): V {0} {}

    void addEdge(string src, string dest, int wt, bool bidir=true)
    {
        gal[src].push_back(make_pair(dest, wt));
        if (bidir)
        {
            gal[dest].push_back(make_pair(src, wt));
        }
        V++;
    }

    void print()
    {
        for (auto & source : gal)
        {
            string src = source.first;
            auto destinations = source.second;
            cout << src << "--> ";
            for (auto & destination : destinations)
            {
                cout << '{' << destination.first << ' ' << destination.second << "} ";
            }
            cout << '\n';
        }
    }
};

int main()
{
    Graph city_map;
    city_map.addEdge("Delhi", "Amritsar", 1);
    city_map.addEdge("Lucknow", "Delhi", 3);
    city_map.addEdge("Delhi", "Jaipur", 2);
    city_map.addEdge("Bhopal", "Delhi", 6);
    city_map.addEdge("Amritsar", "Jaipur", 5);
    city_map.addEdge("Jaipur", "Bhopal", 4);
    city_map.print();
}