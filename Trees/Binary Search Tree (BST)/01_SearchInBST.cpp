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

struct Node {
    int key;
    Node *right;
    Node *left;

    Node(int x) {
        key = x;
        right = NULL;
        left = NULL;
    }
};


Node *searchBST(Node* root, int val) 
{
    if (root == NULL)
        return NULL;

    if (root->key == val)
        return root;

    if (root->key < val)
        return searchBST(root->right, val);
    else
        return searchBST(root->left, val);

}

int main()
{
    Node *root = new Node(10);
    Node *a = root -> left = new Node(7);
    Node *b = root -> left -> left = new Node(4);
    Node *c = root -> left -> right = new Node(8);
    Node *d = root -> right = new Node(13);
    Node *e = root -> right -> left = new Node(6);
    Node *f = root -> right -> right = new Node(12);

    Node *curr = searchBST(root, 13);
    cout<<curr->key<<endl;
}

//         10
//    7          13
// 4     8    11     
//               12
