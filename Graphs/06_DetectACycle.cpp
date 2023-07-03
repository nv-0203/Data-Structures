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

bool BFS(int node, vector<int> adj[], vector<int> &vis)
{
    vis[node] = 1;
    queue<pair<int, int>> q;
    q.push({node, -1});

    while (!q.empty())
    {
        pair<int,int> top = q.front();
        q.pop();

        for (auto it : adj[top.first])
        {
            if (it != top.second)
            {
                if (!vis[it])
                {
                    vis[it] = 1;
                    q.push({it, top.first});
                }
                else
                    return true;
            }
        }
    }
    return false;
}

bool DFS(int node, int parent,  vector<int> adj[], vector<int> &vis)
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (it != parent)
        {
            if (!vis[it])
            {
                if (DFS(it, node, adj, vis) == true)
                    return true;
            }
            else
                return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) 
{
    vector<int> vis(V, 0);
    
    for (int i=0; i<V; i++)
    {
        if (!vis[i] && BFS(i, adj, vis))        //BFS code
            return true;

        // if (!vis[i] && DFS(i, -1, adj, vis))     DFS code
        //     return true;
    }
    return false;
}

int main()
{
    int n, m;
    cin>>n>>m;
    vector<int> adjlist[n];
    for (int i=0; i<m; i++)
    {
        int u, v;
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    cout<<isCycle(n, adjlist);
}

