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
Function to find sum of weights of edges of the Minimum Spanning Tree
using Prim's Algorithm
*/

void spanningTree(int V, vector<vector<int>> adj[])
{
    priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
    vector<int> vis(V, 0);

    int sum = 0;    //sum of weights of MST
    pq.push({0, 0, -1}); //{wt, node, parent}

    vector<int> MST[V]; //contains the Minimum Spanning Tree

    while (!pq.empty())
    {
        auto x = pq.top();
        int wt = x[0];
        int node = x[1];
        int par = x[2];
        pq.pop();

        if (vis[node] == 1)
            continue;

        sum += wt;
        vis[node] = 1;
        if (par != -1)  
        {
            MST[node].push_back(par);
            MST[par].push_back(node);
        }

        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edgeWt = it[1];

            if (!vis[adjNode])
            {
                pq.push({edgeWt, adjNode, node});
            }
        }
    }

    for (int i=0; i<V; i++)
    {
        cout<<i<<" : ";
        for (auto x : MST[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    cout<<"Sum : "<<sum<<endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        spanningTree(V, adj);
    }

    return 0;
}
