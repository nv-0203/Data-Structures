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

    void buildrf(int n, int x, int lx , int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < n)
                sums[x] = 1;
            return;
        }
        int m = (lx + rx)/2;
        buildrf(n, 2*x + 1, lx, m);
        buildrf(n, 2*x + 2, m, rx);

        sums[x] = sums[2*x + 1] + sums[2*x + 2];
    }

    void build(int n)
    {
        buildrf(n, 0, 0, size);    
    }

    void setrf(int i, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            sums[x] = 0;
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
        if (k >= sums[2*x + 2])
            return findrf(k - sums[2*x + 2], 2*x + 1, lx, m);
        else
            return findrf(k , 2*x + 2, m, rx);
    }

    ll find(int k)
    {
        return findrf(k, 0, 0, size);
    }
};

int main() 
{
    int n;
    cin>>n;

    segtree st;
    st.init(n);

    vector<ll> a(n);
    for (int i=0; i<n; i++)
        cin>>a[i];

    st.build(n);
    vector<int> p(n);

    for (int i=n-1; i>=0; i--)
    {
        p[i] = st.find(a[i]) + 1;   //find a[i]th one from the RHS

        st.set(p[i] - 1);
    }

    for (auto it: p)
        cout<<it<<" ";
}