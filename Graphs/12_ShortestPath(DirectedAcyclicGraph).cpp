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

void DFS(int node, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &dfs)
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        int child = it.first;
        if (!vis[child])
            DFS(child, adj, vis, dfs);
    }
    dfs.push(node);
}

vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    vector<pair<int, int>> adj[N];
    for (int i = 0; i < M; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int x = edges[i][2];

        adj[u].push_back({v, x});
    }

    stack<int> stk;
    vector<int> vis(N, 0);

    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
            DFS(i, adj, vis, stk);
    }

    vector<int> dist(N, 1e9);
    dist[0] = 0;

    while (!stk.empty())
    {
        int x = stk.top();
        stk.pop();

        for (auto it : adj[x])
        {
            int node = it.first;
            int val = it.second;

            if (dist[x] + val < dist[node])
                dist[node] = dist[x] + val;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (dist[i] == 1e9)
            dist[i] = -1;
    }

    return dist;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        vector<int> res = shortestPath(n, m, edges);
        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}
