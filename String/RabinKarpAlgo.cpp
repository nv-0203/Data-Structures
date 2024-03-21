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
#define d 256   //no of charachters

//Robin Karp Algorithm is used for pattern searching
/*
Algo:
hash( txt[s+1 .. s+m] ) = ( d*(hash( txt[s .. s+m-1]) – txt[s]*h) + txt[s + m] ) mod q

hash( txt[s .. s+m-1] ) : Hash value at shift s
hash( txt[s+1 .. s+m] ) : Hash value at next shift (or shift s+1) 
d: Number of characters in the alphabet 
q: A prime number 
h: d^(m-1)

*/


vector<int> RobinKarp(string txt, string pattern)
{
    vector<int> ans;
    ll n = txt.length();
    ll m = pattern.length();

    ll t = 0;  //hash value of text
    ll p = 0;  //hash value of pattern

    ll h = 1;  //d^(m-1)
    
    for (int i=0; i<m-1; i++)
        h = (h * d)%mod;

    //Calculating value of p and intial value of t
    for (int i=0; i<m; i++)
    {
        p = (p*d + pattern[i])%mod;
        t = (t*d + txt[i])%mod;
    }

    for (int i=0; i<=(n-m); i++)
    {
        if (p == t) //check if they actually match as their values are matching
        {
            int j=0;
            for (; j<m; j++)
            {
                if (pattern[j] != txt[i+j])
                    break;
            }
            if (j == m)
                ans.push_back(i);
        }

        if (i < n-m)
        {
            t = ( d*(t - txt[i]*h) + txt[i+m])%mod;
            
            if (t<0)
                t = (t+mod);
        }
    }
    return ans;
}

int main() 
{
    string txt, pattern;
    cin>>txt>>pattern;

    vector<int> res = RobinKarp(txt, pattern);
    cout<<"Pattern is found at Indices: "<<endl;
    for (auto idx: res)
        cout<<idx<<" ";
    
}