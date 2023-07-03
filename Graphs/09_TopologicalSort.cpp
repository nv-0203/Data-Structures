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

// linear ordereing or vertices such that if there is an edge between u & v, 
//u appears before v in that ordering

//Topological Sorting can be applied only on Directed Acyclic Graphs

void DFS(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfs)
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            DFS(it, adj, vis, dfs);
        }
    }
    dfs.push_back(node);
} 

vector<int> topoSort(int V, vector<int> adj[]) 
{
    vector<int> ans;
    vector<int> vis(V, 0);
    
    for (int i=0; i<V; i++)
    {
        if (!vis[i])
            DFS(i, adj, vis, ans);
    }
    reverse(ans.begin(), ans.end());
    
    return ans;
    
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

    vector<int> topsort;
    topsort = topoSort(n, adjlist);

    for (auto &value : topsort)
    {
        cout<<value<<" ";
    }
    cout<<endl;
    
}

