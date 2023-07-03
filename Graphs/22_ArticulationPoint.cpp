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

/*
Articulation Points of a graph are the nodes on whose removal, the graph breaks into multiple components. 

-> vector<int> tin
Time of insertion: Dring the DFS call, the time when a node is visited

-> vector<int> low
Lowest time of insertion: In this case, the current node refers to all its adjacent nodes 
                            except the parent and the visited nodes and 
                            takes the minimum lowest time of insertion into account. 


*/

int cnt = 1;
void solve(vector<int> adj[], int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, vector<int> &mark)
{
    vis[node] = 1;
    tin[node] = cnt;
    low[node] = cnt;
    cnt++;

    int child = 0;
    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        if (!vis[it])
        {
            solve(adj, it, node, vis, tin, low, mark);

            low[node] = min(low[node], low[it]);

            if (tin[node] <= low[it] && parent != -1)
                mark[node] = 1;

            child++;
        }
        else
        {
            low[node] = min(low[node], tin[it]);
        }
    }

    if (child > 1 && parent == -1)
        mark[node] = 1;
}

vector<int> articulationPoints(int n, vector<int> adj[])
{
    vector<int> tin(n);
    vector<int> low(n);
    vector<int> vis(n, 0);
    vector<int> mark(n, 0);

    for (int i = 0; i < n; i++)
    {
        solve(adj, i, -1, vis, tin, low, mark);
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (mark[i] == 1)
            ans.push_back(i);
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> adj[n];
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> ans = articulationPoints(n, adj);
        for (auto i : ans)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
