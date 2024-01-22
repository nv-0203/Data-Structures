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
    vector<ll> sums;
    int size;

    void init(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;

        sums.assign(2*size, 0ll);
    }

    void buildrf(vector<ll> &a, int x, int lx , int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (int)a.size())
                sums[x] = a[lx];
            return;
        }
        int m = (lx + rx)/2;
        buildrf(a, 2*x + 1, lx, m);
        buildrf(a, 2*x + 2, m, rx);

        sums[x] = sums[2*x + 1] + sums[2*x + 2];
    }

    void build(vector<ll> &a)
    {
        buildrf(a, 0, 0, size);    
    }

    void setrf(int i, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            sums[x] = 1 - sums[x];
            return;
        }

        int m = (lx + rx)/2;

        if (i < m)  //index lies in left half
            setrf(i, 2*x + 1, lx, m);
        else
            setrf(i, 2*x + 2, m, rx);

        sums[x] = sums[2*x + 1] + sums[2*x + 2];
    }

    void set(int i)
    {
        setrf(i, 0, 0, size);
    }

    ll findrf(int k, int x, int lx, int rx)
    {
        if (rx - lx == 1)
            return lx;

        int m = (lx + rx)/2;
        if (k < sums[2*x + 1])
            return findrf(k, 2*x + 1, lx, m);
        else
            return findrf(k - sums[2*x + 1], 2*x + 2, m, rx);
    }

    ll find(int k)
    {
        return findrf(k, 0, 0, size);
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

        if (op == 1)
        {
            int i;
            cin>>i;

            st.set(i);
        }
        
        else if (op == 2)   //find the index of the k-th one
        {
            int k;
            cin>>k;
            cout<<st.find(k)<<"\n";
        }
    }
}