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

vector<int> BFS(int node, vector<int> adj[], vector<int> &vis)
{
    vis[node] = 1;
    queue<int> q;
    q.push(node);
    vector<int> bfs;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

int main()
{
    int n, m;
    cin>>n>>m;
    vector<int> adjlist[n+1];
    for (int i=0; i<m; i++)
    {
        int u, v;
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    vector<int> vis(n+1, 0);    //1 - based indexing
    vector<int> bfs = BFS(1, adjlist, vis);
    for (auto &value:bfs)
    {
        cout<<value<<" ";
    }
}

