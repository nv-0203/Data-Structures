#include <bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>> &rGraph, int n, int s, int t, vector<int> &parent)
{
    vector<bool> vis(n, false);

    queue<int> q;
    q.push(s);
    vis[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++)
        {
            if (vis[v] == false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                vis[v] = true;
            }
        }
    }

    return (vis[t] == true);
}

void dfs(vector<vector<int>> &rGraph, int n, int s, vector<bool> &vis)
{
    vis[s] = true;
    for (int i = 0; i < n; i++)
        if (rGraph[s][i] && !vis[i])
            dfs(rGraph, n, i, vis);
}

// Prints the minimum s-t cut
void minCut(vector<vector<int>> &graph, int n, int s, int t)
{
    int u, v;

    vector<vector<int>> rGraph = graph; // Residual Graph
    for (u = 0; u < n; u++)
        for (v = 0; v < n; v++)
            rGraph[u][v] = graph[u][v];

    vector<int> parent(n);

    int max_flow = 0;
    while (bfs(rGraph, n, s, t, parent))
    {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    vector<bool> vis(n, false);
    dfs(rGraph, n, s, vis);

    int min_cut = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (vis[i] && !vis[j] && graph[i][j])
            {    
                cout << i << " - " << j << endl;
                min_cut += graph[i][j];
            }
        }

    cout<<min_cut<<endl;
    return;
}

int main()
{
    int n, m;
    cin >> n >> m;

    int s, t;
    cin >> s >> t;

    vector<vector<int>> graph(n, vector<int>(n));

    for (int i=0; i<m; i++)
    {
        int u, v, w;
        cin>>u>>v>>w;

        graph[u][v] = w;
    }

    minCut(graph, n, s, t);

    return 0;
}

/*
Algorithm:
1. Run the Ford-Fulkerson algorithm and consider the final residual graph. 
2. Find the set of vertices that are reachable from the source in the residual graph. 
3. All edges which are from a reachable vertex to a non-reachable vertex are minimum cut
     edges. Print all such edges.
*/