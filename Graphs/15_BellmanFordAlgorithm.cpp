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

//Single Source shortest path

/*
Bellman Ford Algo gives shortest distance to all vertices from source
It works fine with negative edges as well as it is able to detect if the graph contains a negative cycle.
*/

//this algorithm is only applicable for directed graphs

/*  Function to implement Bellman Ford
 *   edges: vector of vectors which represents the graph
 *   S: source vertex to start traversing graph with
 *   V: number of vertices
 */

vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
{
    int m = edges.size();
    vector<int> dist(V, 1e8);
    dist[S] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0]; // source vertex
            int v = edges[j][1]; // distance vertex
            int w = edges[j][2]; // distance between u & v

            if (dist[u] != 1e8 && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    // Nth relaxation to check negative cycle
    for (int j = 0; j < m; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if (dist[u] != 1e8 && dist[u] + w < dist[v])
            return {-1};
    }

    return dist;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        vector<int> res = bellman_ford(N, edges, src);

        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}

/* Since in a graph of N nodes, in worst case, you will take N-1 edges
from first to last, thereby we iterate for N-1 iterations
*/