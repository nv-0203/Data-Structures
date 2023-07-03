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

// Kosaraju's Algorithm is used to find no of Strongly Connected Componenets in a graph

/*
A directed graph is strongly connected if there is a path between all pairs of vertices. 
A strongly connected component (SCC) of a directed graph is a maximal strongly connected subgraph.
*/

/*
Algo:
1. Create an empty stack and do DFS traversal of a graph. 
    In DFS traversal, after calling recursive DFS for adjacent vertices of a vertex, push the vertex to stack. 
2. Reverse directions of all edges to obtain the transpose graph. 
3. One by one pop a vertex from S while S is not empty. 
    Let the popped vertex be 'v'. Take v as source and do DFS (call DFSUtil(v)). 
    The DFS starting from v prints strongly connected component of v. 
*/

void DFS(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st)
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
            DFS(it, adj, vis, st);
    }
    st.push(node);
}

void DFS1(int node, vector<int> adjT[], vector<int> &vis)
{
    vis[node] = 1;
    for (auto it : adjT[node])
    {
        if (!vis[it])
            DFS1(it, adjT, vis);
    }
}

// Function to find number of strongly connected components in the graph.
int kosaraju(int V, vector<vector<int>> &adj)
{
    // 1. sort by finishing time
    vector<int> vis(V, 0);
    stack<int> stk;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            DFS(i, adj, vis, stk);
    }

    // 2. reverse direction of all the edges
    vector<int> adjT[V]; // adjacency list with reverse edges
    for (int i = 0; i < V; i++)
    {
        vis[i] = 0; // making visited vector zero again
        for (auto it : adj[i])
        {
            adjT[it].push_back(i);
        }
    }

    // 3. apply dfs again
    int ans = 0;
    while (!stk.empty())
    {
        int node = stk.top();
        stk.pop();
        if (!vis[node])
        {
            ans++;
            DFS1(node, adjT, vis);
        }
    }

    return ans;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        cout << kosaraju(V, adj) << "\n";
    }

    return 0;
}
