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

//Tarjan's Algorithm is used to calculate the no of bridge in a graph

/*
A bridge is any edge in a component of a graph 
when the component is divided into 2 or more components if we remove that particular edge.

vector<int> tin: Time of insertion: Dring the DFS call, the time when a node is visited
vector<int> low: Lowest time of insertion: In this case, 
                    the current node refers to all its adjacent nodes except the parent and takes the minimum lowest time of insertion into account
*/

static int cnt = 1;

void solve(vector<int> adj[], int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, vector<vector<int>> &ans)
{
    vis[node] = 1;
    tin[node] = cnt;
    low[node] = cnt;
    cnt++;

    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        if (!vis[it])
        {
            solve(adj, it, node, vis, tin, low, ans);

            low[node] = min(low[node], low[it]);

            if (tin[node] < low[it])
                ans.push_back({node, it});
        }
        else
        {
            low[node] = min(low[node], low[it]);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adjlist[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    
    vector<int> tin(n);
    vector<int> low(n);
    vector<int> vis(n, 0);
    vector<vector<int>> ans;

    solve(adjlist, 0, -1, vis, tin, low, ans);

    for (auto it:ans)
    {
        cout<<it[0]<<" "<<it[1]<<endl;
    }

    
}
