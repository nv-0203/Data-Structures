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

class Node
{
    public:
    int val;
    Node *right;
    Node *left;

    Node(int x)
    {
        val = x;
        right = NULL;
        left = NULL;
    }
};

/*
Given the root of a binary tree, flatten the tree into a "linked list":

-> The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
-> The "linked list" should be in the same order as a pre-order traversal of the binary tree.

*/

void flatten(Node* root, Node** prev) 
{
    if (root != NULL)
    {
        flatten (root->right, prev);
        flatten (root->left, prev);

        root -> right = *prev;
        root -> left = NULL;
        *prev = root;
    }
    
}

int main()
{
    Node *root = new Node(1);
    root -> left = new Node(2);
    Node *p = root -> left -> left = new Node(4);
    Node *q = root -> left -> right = new Node(5);
    Node *r = root -> right = new Node(3);
    root -> right -> left = new Node(6);
    root -> right -> left -> right = new Node(7);
    root -> right -> left -> right -> right = new Node(8);

    Node *prev = NULL;
    flatten(root, &prev);


    
}

//         1
//    2          3
// 4     5    6     
//               7
//                  8