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

/*
KMP (Knuth Morris Pratt) Pattern Searching:

The basic idea behind KMP’s algorithm is: 
whenever we detect a mismatch (after some matches), 
we already know some of the characters in the text of the next window. 
We take advantage of this information to avoid matching the characters that we know will anyway match.

Time Complexity -> O(n+m)
Space Comlexity -> O(m)
*/

//LPS: longest prefix same as suffix. Also known as pi-table
vector<int> generateLPS(string pat) 
{
    int m = pat.length();
    vector<int> lps(m, 0);

    for (int i=1; i<m; i++)
    {
        int j = lps[i-1];

        while (j>0 && pat[i] != pat[j]) //find the index of a previous occurence of the element i or j = 0
            j = lps[j-1];
        
        if (pat[i] == pat[j])
            j++;

        lps[i] = j;
    }

    return lps;
}

vector<int> KMP(string txt, string pat)
{
    vector<int> ans;
    int n = txt.length();
    int m = pat.length();
    
    vector<int> lps = generateLPS(pat);

    int j=0;    //tracks the pattern string

    for (int i=0; i<n; i++)
    {
        while (i<n && j<m && txt[i] == pat[j])
        {
            i++;
            j++;
        }

        if (j == m)
            ans.push_back(i-j);

        /*
        1. txt is still left
        2. char doesn't match
        3. pointer is not to the first char of pat

        Thus,
        we go to the previous occurence of the last char for which it matched 
        hence j = lps[j-1]  (we're taking lps of j-1 since that is the char which was last matching)
        i-- since sue to for loop it will become i++ so it remains at that point itself 
        */
        if (j!=0 && i!=n)
        {
            j = lps[j-1];
            i--;
        }
    }

    return ans;
}

int main() 
{
    string txt, pat;
    cin>>txt>>pat;

    vector<int> res = KMP(txt, pat);
    cout<<"Pattern is found at following indices: ";
    for (auto idx: res)
        cout<<idx<<" ";
    
}