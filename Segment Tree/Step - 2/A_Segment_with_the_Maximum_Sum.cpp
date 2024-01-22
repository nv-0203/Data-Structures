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

struct item{
    ll seg; //maximum sum of numbers on the segment
    ll pref;    //sum of maximal prefix of the segment
    ll suff;    //sum of maximal suffix of the segment
    ll sum;     //sum of all elements of the segment
};

struct segtree{
    vector<item> vals;
    int size;

    //item NEUTRAL_ELEMENT = {INT_MAX, 0};

    item merge(item a, item b)
    {
        item res;
        res.seg = max(a.seg, max(b.seg, a.suff + b.pref));
        res.pref = max(a.pref, a.sum + b.pref);
        res.suff = max(b.suff, b.sum + a.suff);
        res.sum = a.sum + b.sum;

        return res;
    }

    item single(int v)
    {
        return {max(0, v), max(0, v), max(0, v), v};
    }

    void init(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;

        vals.resize(2*size);
    }

    void buildrf(vector<int> &a, int x, int lx , int rx)
    {
        if (rx - lx == 1)
        {
            if (lx < (int)a.size())
                vals[x] = single(a[lx]);
            return;
        }

        int m = (lx + rx)/2;
        buildrf(a, 2*x + 1, lx, m);
        buildrf(a, 2*x + 2, m, rx);

        vals[x] = merge(vals[2*x + 1], vals[2*x + 2]);
    }

    void build(vector<int> &a)
    {
        buildrf(a, 0, 0, size);    
    }

    void setrf(int i, int v, int x, int lx, int rx)
    {
        if (rx - lx == 1)
        {
            vals[x] = single(v);
            return;
        }

        int m = (lx + rx)/2;

        if (i < m)  //index lies in left half
            setrf(i, v, 2*x + 1, lx, m);
        else
            setrf(i, v, 2*x + 2, m, rx);

        vals[x] = merge(vals[2*x + 1], vals[2*x + 2]);
    }

    void set(int i, int v)
    {
        setrf(i, v, 0, 0, size);
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

    //Print m+1 lines: the maximum sum of numbers on a segment before all operations and after each operation

    cout<<st.vals[0].seg<<endl;
    while (m--)
    {
        int i, v;
        cin>>i>>v;

        st.set(i, v);
        
        cout<<st.vals[0].seg<<endl;
    }
}