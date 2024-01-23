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

    ll sumrf(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || l >= rx)
            return 0;

        if (lx >= l && rx <= r)
            return sums[x];

        int m = (lx + rx)/2;
        
        ll s1 = sumrf(l, r, 2*x + 1, lx, m);
        ll s2 = sumrf(l, r, 2*x + 2, m, rx);

        return s1 + s2;
    }

    ll sum(int l, int r)
    {
        return sumrf(l, r, 0, 0, size);
    }
};

int main() 
{
    int n;
    cin>>n;

    segtree st;
    st.init(2*n);

    vector<ll> a(2*n);
    for (int i=0; i<2*n; i++)
        cin>>a[i];

    vector<int> ans(n+1, 0);
    map<int, int> mp;
    
    //first from left to right
    for (int i=0; i<2*n; i++)   
    {
        if (mp.find(a[i]) == mp.end())
        {
            mp[a[i]] = i;
            st.set(i);
        }
            
        else
        {
            ans[a[i]] += st.sum(mp[a[i]] + 1, i);
            st.set(mp[a[i]]);
            mp.erase(a[i]);
        }
    }

    //then right to left
    mp.clear();
    reverse(a.begin(), a.end());    

    for (int i=0; i<2*n; i++)
    {
        if (mp.find(a[i]) == mp.end())
        {
            mp[a[i]] = i;
            st.set(i);
        }
            
        else
        {
            ans[a[i]] += st.sum(mp[a[i]] + 1, i);
            st.set(mp[a[i]]);
            mp.erase(a[i]);
        }
    }

    for (int i=1; i<=n; i++)
        cout<<ans[i]<<" ";
}