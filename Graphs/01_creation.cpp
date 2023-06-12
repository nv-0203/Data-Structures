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

int main()
{
    int n, m;
    cin>>n>>m;

    //Method 1: Using Adjacency Matrix (directed)
    int adj[n+1][n+1];
    for (int i=0; i<m; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u][v] = 1;
        //adj[v][u] = 1;  (undirected)
    }

    //Method 2: Using list (directed)
    vector<int> adjlist[n+1];
    for (int i=0; i<m; i++)
    {
        int u, v;
        cin>>u>>v;
        adjlist[u].push_back(v);
        //adjlist[v].push_back(u);  (undirected)  
    }
    return 0;
}