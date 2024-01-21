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
    vector<int> vals;
    int size;

    void init(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;

        vals.assign(2*size, 0ll);
    }

    void buildrf(vector<int> &a, int x, int lx , int rx)
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

        vals[x] = min(vals[2*x + 1], vals[2*x + 2]);
    }

    void build(vector<int> &a)
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

        vals[x] = min(vals[2*x + 1], vals[2*x + 2]);
    }

    void set(int i, int v)
    {
        setrf(i, v, 0, 0, size);
    }

    int calcrf(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || l >= rx)
            return INT_MAX;

        if (lx >= l && rx <= r)
            return vals[x];

        int m = (lx + rx)/2;
        
        int s1 = calcrf(l, r, 2*x + 1, lx, m);
        int s2 = calcrf(l, r, 2*x + 2, m, rx);

        return min(s1, s2);
    }

    int calc(int l, int r)
    {
        return calcrf(l, r, 0, 0, size);
    }
};

int main() 
{
    int n, m;
    cin>>n>>m;

    segtree st;
    st.init(n);

    vector<int> a(n);
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

        else if (op == 2)   //calculate the minimum of elements with indices from l to r−1
        {
            int l, r;
            cin>>l>>r;

            cout << st.calc(l, r) << endl;
        }
    }
}