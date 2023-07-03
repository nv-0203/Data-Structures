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

//Kahn's Algorithm is used to get topological sort using BFS technique

vector<int> topoSort(int V, vector<int> adj[]) 
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

    vector<int> ans = topoSort(n, adjlist);

    for (auto &value:ans)
    {
       cout<<value<<" ";
    }
    cout<<endl;
}

