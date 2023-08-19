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

void heapify(int arr[], int N, int i)
{

    int largest = i;

    int l = 2*i + 1;
    int r = 2*i + 2;
 
    if (l < N && arr[l] > arr[largest])
        largest = l;

    if (r < N && arr[r] > arr[largest])
        largest = r;
 
    if (largest != i) 
    {
        swap(arr[i], arr[largest]);
        heapify(arr, N, largest);
    }
}

void heapSort(int arr[], int N)
{
    //creating a heap
    for (int i = N / 2 - 1; i >= 0; i--)    //we just need to heapify all the root elements
    {
        heapify(arr, N, i);
    }
 
    for (int i = N - 1; i > 0; i--) 
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() 
{
    int n;  cin>>n;
    int arr[n];
    for (int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    heapSort(arr, n);
    for (int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}