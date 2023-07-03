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

int orangesRotting(vector<vector<int>>& grid) 
{
    int n = grid.size();
    int m = grid[0].size();
    int cntFresh = 0;
    queue<pair<pair<int, int> , int>> que;
    vector<vector<int>> vis(n, vector<int> (m, 0));
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if (grid[i][j] == 2)
            {
                que.push({{i, j}, 0});
            }
            if (grid[i][j] == 1)
                cntFresh++;
        }
    }
    int cnt = 0;
    int total = 0;
    while (!que.empty())
    {
        pair<pair<int, int>, int> node = que.front();
        int t = node.second;
        pair<int, int> x = node.first;
        int i = x.first;
        int j = x.second;
        vis[i][j] = 2;
        total = max(total, t);
        que.pop();
        for (auto pair : {make_pair(i, j-1), make_pair(i-1, j), make_pair(i, j+1), make_pair(i+1, j)}) 
        {
            int I = pair.first;
            int J = pair.second;
            
            if (I>=0 && J>=0 && I<n && J<m && vis[I][J] == 0 && grid[I][J] == 1)
            {
                vis[I][J] = 2;
                que.push({{I, J}, t+1});
                cnt++;
            }
        }
    }
    
    if (cnt == cntFresh)
        return total;
    return -1;
}

int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> grid(n, vector<int> (m));
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cin>>grid[i][j];
        }
    }

    cout<<orangesRotting(grid);
}

