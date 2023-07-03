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

void DFS(char node, unordered_map<char, vector<char>> adj, unordered_map<char, int> &vis, string &dfs)
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (vis.find(it) == vis.end())
        {
            DFS(it, adj, vis, dfs);
        }
    }
    dfs += node;
}

string findOrder(string dict[], int N, int K) 
{
    unordered_map<char, vector<char>> adj;
    for (int i=0; i<N-1; i++)
    {
        int n = dict[i].size();
        int m = dict[i+1].size();
        
        int x = min(n, m);
        for (int j=0; j<x; j++)
        {
            if (dict[i][j] != dict[i+1][j])
            {
                char p = dict[i][j];
                char c = dict[i+1][j];
                adj[p].push_back(c);
                break;
            }
        }
    }
    
    unordered_map<char, int> vis;
    string ans;
    
    for (int i=0; i<N; i++)
    {
        int x = dict[i].size();
        for (int j=0; j<x; j++)
        {
            char c = dict[i][j];
            if (vis.find(c) == vis.end())
            {
                DFS(c, adj, vis, ans);
            }
        }
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
    
    
}

int main()
{
    int n, k;
    cin>>n>>k;
    string dict[n];
    for (int i=0; i<n; i++)
    {
        cin>>dict[i];
    }

    string ans;
    ans = findOrder(dict, n, k);

    for (auto &value:ans)
    {
       cout<<value<<" ";
    }
}

