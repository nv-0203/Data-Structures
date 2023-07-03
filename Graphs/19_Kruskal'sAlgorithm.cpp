#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long long int ll;

class DisjointSet
{
    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUParent(int node)
    {
        if (parent[node] == node)
            return node;

        return parent[node] = findUParent(parent[node]);
    }

    void Union(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;

        else if (rank[ulp_u] > rank[ulp_v])
            parent[ulp_v] = ulp_u;

        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_v]++;
        }
    }
};

/* Function to find sum of weights of edges of the Minimum Spanning Tree.
using Kruskal's Algorithm:
1. Sort all the edges in non-decreasing order of their weight. 
2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. 
        If the cycle is not formed, include this edge. Else, discard it. (using disjoint set) 
3. Repeat step#2 until there are (V-1) edges in the spanning tree.

*/
int spanningTree(int V, vector<vector<int>> adj[])
{
    int sum = 0;
    vector<pair<int, pair<int, int>>> vect;

    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            int wt = it[1];
            int u = i;
            int v = it[0];
            vect.push_back({wt, {u, v}});
        }
    }

    sort(vect.begin(), vect.end());
    DisjointSet ds(V);

    for (auto it : vect)
    {
        int u = it.second.first;
        int v = it.second.second;
        int wt = it.first;

        if (ds.findUParent(u) != ds.findUParent(v))
        {
            sum += wt;
            ds.Union(u, v);
        }
    }

    return sum;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        cout << spanningTree(V, adj) << "\n";
    }

    return 0;
}