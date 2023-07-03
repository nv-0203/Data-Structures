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

bool BFS(int V, vector<int> adj[])  //Using Kahn's Algorithm
{
    vector<int> indegree(V, 0);
    for (int i=0; i<V; i++)
    {
        for (auto it:adj[i])
        {
            indegree[it]++;
        }
    }
    
    queue<int> q;
    for (int i=0; i<V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    
    vector<int> ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    
    if (ans.size() != V)
        return true;
    return false;
}

bool DFS(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis)
{
    vis[node] = 1;
    pathVis[node] = 1;
    
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (DFS(it, adj, vis, pathVis) == true)
                return true;
        }
        else if (vis[it] && pathVis[it])
        {
            return true;
        }
    }
    pathVis[node] = 0; 
    return false;
    
}

bool isCyclic(int V, vector<int> adj[]) 
{
    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);
    
    for (int i=0; i<V; i++)     //DFS method
    {
        if (!vis[i])
        {
            bool res = DFS(i, adj, vis, pathVis);
            if (res == true)    return true;
        }
    }
    return false;

    //return BFS(V, adj);   //BFS method
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
    }

    cout<<isCyclic(n, adjlist);
}

