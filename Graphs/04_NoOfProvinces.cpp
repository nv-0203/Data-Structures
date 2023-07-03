// A province is a group of directly or indirectly connected vertices and no other vertices outside of the group.
//We say two vertices u and v belong to a single province if there is a path from u to v or v to u.

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

void BFS(int node, vector<int> adj[], vector<int> &vis)
{
    vis[node] = 1;
    queue<int> q;
    q.push(node);
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        for (auto it : adj[top])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
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

    vector<int> vis(n+1, 0);
    int ans = 0;
    for (int i=1; i<=n; i++)
    {
        if (!vis[i])
        {
            ans++;
            BFS(i, adjlist, vis);
        }
    }
    cout<<ans;
}

