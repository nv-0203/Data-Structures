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

void DFS(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfs)
{
    vis[node] = 1;
    dfs.push_back(node);

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            DFS(it, adj, vis, dfs);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adjlist[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    vector<int> vis(n + 1, 0);
    vector<int> dfs;
    DFS(1, adjlist, vis, dfs);
    for (auto &value : dfs)
    {
        cout << value << " ";
    }
}