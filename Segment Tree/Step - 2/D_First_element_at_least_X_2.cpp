#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <iomanip>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define eps 1e-9
#define mod 1000000007

struct segtree{
    vector<ll> vals;
    int size;

    void init(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;

        vals.assign(2*size, -1);
    }

    void buildrf(vector<ll> &a, int x, int lx , int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (int)a.size())
                vals[x] = a[lx];
            return;
        }

        int m = (lx + rx)/2;
        buildrf(a, 2*x + 1, lx, m);
        buildrf(a, 2*x + 2, m, rx);

        vals[x] = max(vals[2*x + 1], vals[2*x + 2]);
    }

    void build(vector<ll> &a)
    {
        buildrf(a, 0, 0, size);    
    }

    void setrf(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            vals[x] = v;
            return;
        }

        int m = (lx + rx)/2;

        if (i < m)  //index lies in left half
            setrf(i, v, 2*x + 1, lx, m);
        else
            setrf(i, v, 2*x + 2, m, rx);

        vals[x] = max(vals[2*x + 1], vals[2*x + 2]);
    }

    void set(int i, int v)
    {
        setrf(i, v, 0, 0, size);
    }

    int findrf(int k, int l, int x, int lx, int rx)
    {
        if (vals[x] < k || rx <= l)
            return -1;

        if (rx - lx == 1)
            return lx;

        int m = (lx + rx)/2;

        int res = findrf(k, l, 2*x + 1, lx, m);
        if (res == -1)
            res = findrf(k, l, 2*x + 2, m, rx);

        return res;
    }

    int find(int k, int l)
    {
        return findrf(k, l, 0, 0, size);
    }
};

int main() 
{
    int n, m;
    cin>>n>>m;

    segtree st;
    st.init(n);

    vector<ll> a(n);
    for (int i=0; i<n; i++)
        cin>>a[i];

    st.build(a);

    while (m--)
    {
        int op;
        cin>>op;

        if (op == 1)    //set the elment with index i to v
        {
            int i, v;
            cin>>i>>v;

            st.set(i, v);
        }

        else if (op == 2)   //find the minimum index j such that j >= l and a[j] >= x. If there is no such element, print −1
        {
            int x, l;
            cin>>x>>l;

            cout << st.find(x, l) << endl;
        }
    }
}