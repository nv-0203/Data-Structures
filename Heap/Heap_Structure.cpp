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

class MaxHeap{
private:
    int *arr;
    int size;
    int capacity;
public:
    MaxHeap(int c)
    {
        arr = new int[c];
        capacity = c;
        size = 0;
    }

    int left(int i)
    {
        return 2*i + 1;
    }
    int right (int i)
    {
        return 2*i+2;
    }
    int parent(int i)
    {
        return (i-1)/2;
    }

    void insert(int val);
    void del();

    int top()
    {
        return arr[0];
    }

    void MaxHeapify(int i);
};

void MaxHeap::insert(int val)
{
    if (size == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    size++;
    arr[size-1] = val;

    int idx = size-1;
    while (idx > 0 && arr[parent(idx)] < arr[idx])
    {
        swap(arr[idx], arr[parent(idx)]);
        idx = parent(idx);
    }
}

void MaxHeap::del() //deleting max node from heap
{
    if (size == 0)
        return;

    arr[0] = arr[size-1]; //putting last element at first
    size--;             //deleting last element. Hence first(max) element is lost

    MaxHeapify(0);

}

void MaxHeap::MaxHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l < size && arr[l] > arr[i])
        largest = l;
    if (r < size && arr[r] > arr[largest])
        largest = r;
    if (largest != i) 
    {
        swap(arr[i], arr[largest]);
        MaxHeapify(largest);
    }
}

int main() 
{
    MaxHeap heap(10);
    heap.insert(13);
    heap.insert(5);
    heap.insert(2);
    cout<<heap.top()<<endl;
    heap.del();
    cout<<heap.top()<<endl;
}