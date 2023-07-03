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

bool BFS(int V, vector<int>adj[], int src, vector<int>&color)
{
    queue<int>q;
    
    q.push(src);
    color[src]=0;
    
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        
        for(auto it : adj[node])
        {
            if(color[it]==-1)
            {
                color[it]=!color[node];
                q.push(it);
            
            }
            else if(color[it]==color[node])
            {
                return false;
            }
        }
    }
    
    return true;
    
}

bool DFS(int node, vector<int> adj[], vector<int> &color, int flag)
{
    color[node] = flag;

    for (auto it : adj[node])
    {
        if (color[it] == -1)
        {
            if (DFS(it, adj, color, !flag) == false)
                return false;
        }
        else if (color[it] == flag)
        {
            return false;
        }
    }
    return true;
}

bool isBipartite(int V, vector<int>adj[])
{
    vector<int> color(V, -1);
    for (int i=0; i<V; i++)
    {
        if (color[i] == -1)
        {
            bool res = DFS(i, adj, color, 0);   //DFS
            if (res == false)
                return false;

            // bool b =BFS(V, adj, i, color);   //BFS
            // if(b==false)  return false;
        }
    }
    return true;
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

    cout<<isBipartite(n, adjlist);
}

