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
Disjoint Set is a data structure that stores non overlapping or disjoint subset of elements.

The disjoint set data structure supports following operations:
-> Merging disjoint sets to a single disjoint set using Union (by Rank OR by Size) operation.
-> Finding representative (ultimate parent) of a disjoint set using parent operation.
-> Check if two sets are disjoint or not. 

*/
class DisjointSet
{
    vector<int> rank, parent, size;
    public:

    DisjointSet(int n)
    {
        rank.resize(n+1, 0);    //stores the rank i.e the max depth a node has
        parent.resize(n+1, 0);
        for (int i=0; i<=n; i++)
            parent[i] = i;      //intially each node is it's own parent
        size.resize(n+1, 1);    //stores the size of each node i.e no of connected components
    }

    int findUParent(int node)   //finding the ultimate parent of any given node and then 
                                //compressing it's path (i.e updating value of a node's parent to it's ultimate parent)
    {
        if (parent[node] == node)   
            return node;

        return parent[node] = findUParent(parent[node]);    //path compression
    }

    void UnionByRank(int u, int v)
    {
        int ulp_u = findUParent(u);  //ultimate parent of u
        int ulp_v = findUParent(v);  //ultimate parent of v

        if (ulp_u == ulp_v)     //nothing needs to be done both are connected components
            return;

        //always attach one with smaller rank to the one with bigger rank
        if (rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;  //here rank doesn't increase as we are attaching one with smaller rank to the bigger one
        
        else if (rank[ulp_u] > rank[ulp_v])
            parent[ulp_v] = ulp_u;

        else
        {
            parent[ulp_v] = ulp_u;  //can go both ways i.e parent[ulp_u] = ulp_v also is fine
            rank[ulp_v]++;
        }
    }

    void UnionBySize(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if (size[ulp_u] < size[ulp_v])  //here it can be equal to as well doesn't make a difference
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        
    }
};

int main()
{
    DisjointSet ds(7);
    ds.UnionByRank(1, 2);
    ds.UnionByRank(2, 3);
    ds.UnionByRank(4, 5);
    ds.UnionByRank(6, 7);
    ds.UnionByRank(5, 6);

    if (ds.findUParent(3) != ds.findUParent(7))
        cout<<"Not Same"<<endl;
    else
        cout<<"Same"<<endl;

    ds.UnionByRank(3, 7);

    if (ds.findUParent(3) != ds.findUParent(7))
        cout<<"Not Same"<<endl;
    else
        cout<<"Same"<<endl;
}

/* For-use:

class DisjointSet
{
    vector<int> rank, parent;
    public:

    DisjointSet(int n)
    {
        rank.resize(n+1, 0);    
        parent.resize(n+1, 0);
        for (int i=0; i<=n; i++)
            parent[i] = i;      

    int findUParent(int node)   
    {
        if (parent[node] == node)   
            return node;

        return parent[node] = findUParent(parent[node]);    
    }

    void Union(int u, int v)
    {
        int ulp_u = findUParent(u);  
        int ulp_v = findUParent(v);  

        if (ulp_u == ulp_v)     
            return;

        if (rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;  
        
        else if (rank[ulp_u] > rank[ulp_v])
            parent[ulp_v] = ulp_u;

        else
        {
            parent[ulp_v] = ulp_u;  
            rank[ulp_v]++;
        }
    }
};

*/