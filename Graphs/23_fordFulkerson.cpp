#include <bits/stdc++.h>

using namespace std;

bool bfs(vector<vector<int>> &rGraph, int n, int s, int t, vector<int> &parent)
{
	vector<bool> vis(n, false);

	queue<int> q;
	q.push(s);
	vis[s] = true;
	parent[s] = -1;

	while (!q.empty())
	{
		int u = q.front();
		q.pop();

		for (int v = 0; v < n; v++)
		{
			if (vis[v] == false && rGraph[u][v] > 0)
			{
				parent[v] = u;
				if (v == t)
					return true;
				
				q.push(v);
				vis[v] = true;
			}
		}
	}

	return false;
}

int fordFulkerson(vector<vector<int>> &graph, int n, int s, int t)
{
	vector<vector<int>> rGraph = graph;	//Residual graph

	vector<int> parent(n);

	int max_flow = 0;

	while (bfs(rGraph, n, s, t, parent))	//finding augmented path
	{
		int path_flow = INT_MAX;
		for (int v = t; v != s; v = parent[v])
		{
			int u = parent[v];
			path_flow = min(path_flow, rGraph[u][v]);	//bottleneck capacity
		}

		for (int v = t; v != s; v = parent[v])	//augmenting the path
		{
			int u = parent[v];
			rGraph[u][v] -= path_flow;
			rGraph[v][u] += path_flow;
		}

		max_flow += path_flow;
	}

	return max_flow;
}

int main()
{
	int n, m;
	cin>>n>>m;

	int s, t;
	cin>>s>>t;

	vector<vector<int>> graph(n, vector<int> (n, 0));
	for (int i=0; i<m; i++)
	{
		int u, v, w;
		cin>>u>>v>>w;

		graph[u][v] = w;
	}

	cout << "The maximum possible flow is " << fordFulkerson(graph, n, s, t);

	return 0;
}

/*
Ford - Fulkerson Algorithm:
1. Find an augmented path
2. Compute the bottleneck capacity
3. Augment each edge and the total flow

Augmented Path: A path in the residual graph with unused capacity greater than 0 for each edge
Bottleneck capacity: minimum value of an edge along the path
Augmenting the flow: updating the flow values of the edges along the augmenting path
*/