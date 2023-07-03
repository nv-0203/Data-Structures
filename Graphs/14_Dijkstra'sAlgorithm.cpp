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

//Single sourxe shortest path

// Function to find the shortest distance of all the vertices
// from the source vertex S.

vector<int> set_dijkstra(int V, vector<pair<int, int>> adj[], int S)   //using set
{
    set<pair<int, int>> st;
    vector<int> dist(V, 1e9);
    dist[S] = 0;
    st.insert({0, S});
    while (!st.empty())
    {
        auto x = *(st.begin());
        int node = x.second;
        int dis = x.first;
        st.erase(x);

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edgeWt = it.second;

            if (dist[adjNode] > dis + edgeWt)
            {
                if (dist[adjNode] != 1e9)   // erase if it was visited previously at a greater cost.
                    st.erase({dist[adjNode], adjNode});

                dist[adjNode] = dis + edgeWt;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

vector<int> dijkstra(int V, vector<pair<int, int>> adj[], int S)   //using priority queue
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distTo(V, INT_MAX);

    distTo[S] = 0;
    pq.push({0, S});    //{distance to node x, node x}

    while (!pq.empty())
    {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();

        for (auto it : adj[node])
        {
            int v = it.first;
            int w = it.second;
            if (dis + w < distTo[v])
            {
                distTo[v] = dis + w;
                pq.push({dis + w, v});
            }
        }
    }

    return distTo;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<pair<int, int>> adj[V];     //for each node: each vector stores 2 values
                                            //vect[i].first : destination node  ;  vect[i].second : distance to destination node
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        int S;
        cin >> S;

        vector<int> res = dijkstra(V, adj, S);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

//Time Complexity: O(mlogn)
//m : no of edges
//n : no of vertices

/*  Dijkstra's Algo fails in the following two cases:
-> If the graph contains negative edges.
-> If the graph has a negative cycle 
(In this case Dijkstra’s algorithm fails to minimize the distance, keeps on running, and goes into an infinite loop. As a result it gives TLE error).
*/